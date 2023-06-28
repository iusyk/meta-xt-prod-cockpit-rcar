
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QJsonArray>
#include <limits>
#include <memory>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <exception>
#include <string>
#include <vector>
#include <linux/r_taurus_cluster_protocol.h>
#include "providers/include/Renesas.h"

//struct rpmsg_endpoint_info ept_info = {"rpmsg-openamp-demo-channel", 0x2, 0x1};
const int not_defined_value = std::numeric_limits<int>::max();

struct AosVisParameter {
    vis_string paramName;
    uint32_t ctlIOId;
    int value;
    std::function<int(const vis_string & propId, const vis_string & message)> getValue;
};


class ValueHelper
{
public:
    static int getBool(const vis_string & propId, const vis_string & message);
    static int getTurnDirection(const vis_string & propId, const vis_string & message);
    static int getValue(const vis_string & propId, const vis_string & message);
    static int getTireStatus(const vis_string & propId, const vis_string & message);
    static int getBeltStatus(const vis_string & propId, const vis_string & message);
    static vis_string getStringValue(const vis_string & propId, const vis_string & message);
};

const std::vector<AosVisParameter> aosVisParameters {
    {"Signal.Vehicle.Speed", CLUSTER_SPEED, not_defined_value, ValueHelper::getValue},
    {"Signal.Drivetrain.Transmission.Gear", CLUSTER_GEAR, not_defined_value, ValueHelper::getValue},
    {"Signal.Drivetrain.InternalCombustionEngine.Engine.Speed", CLUSTER_RPM, not_defined_value, ValueHelper::getValue},
    {"Signal.Traffic.Turn.Direction", CLUSTER_TURN, not_defined_value, ValueHelper::getTurnDirection},
    {"Signal.Cabin.Door.Row1.Left.IsOpen", CLUSTER_DOOR_OPEN, not_defined_value, ValueHelper::getBool},
    {"Signal.Cabin.Door.Row1.Right.IsOpen", CLUSTER_DOOR_OPEN, not_defined_value, ValueHelper::getBool},
    {"Signal.Cabin.Door.Row2.Left.IsOpen", CLUSTER_DOOR_OPEN, not_defined_value, ValueHelper::getBool},
    {"Signal.Cabin.Door.Row2.Right.IsOpen", CLUSTER_DOOR_OPEN, not_defined_value, ValueHelper::getBool},
    {"Signal.Body.Trunk.IsOpen", CLUSTER_DOOR_OPEN, not_defined_value, ValueHelper::getBool},
    {"Signal.Cabin.Seat.Row1.Pos1.IsBelted", CLUSTER_SEAT_BELT, not_defined_value, ValueHelper::getBeltStatus},
    {"Signal.Cabin.Seat.Row1.Pos2.IsBelted", CLUSTER_SEAT_BELT, not_defined_value, ValueHelper::getBeltStatus},
    {"Signal.Cabin.Seat.Row2.Pos1.IsBelted", CLUSTER_SEAT_BELT, not_defined_value, ValueHelper::getBeltStatus},
    {"Signal.Cabin.Seat.Row2.Pos2.IsBelted", CLUSTER_SEAT_BELT, not_defined_value, ValueHelper::getBeltStatus},
    {"Signal.Body.Lights.IsLowBeamOn", CLUSTER_LOW_BEAMS_LIGHTS, not_defined_value, ValueHelper::getBool},
    {"Signal.Body.Lights.IsHighBeamOn", CLUSTER_HIGH_BEAMS_LIGHT, not_defined_value, ValueHelper::getBool},
    {"Signal.Body.Lights.IsFrontFogOn", CLUSTER_FOG_LIGHTS_FRONT, not_defined_value, ValueHelper::getBool},
    {"Signal.Body.Lights.IsRearFogOn", CLUSTER_FOG_LIGHTS_BACK, not_defined_value, ValueHelper::getBool},
    {"Signal.Chassis.Axle.Row1.Wheel.Left.Tire.Pressure", CLUSTER_LOW_TIRE_PRESSURE, not_defined_value, ValueHelper::getTireStatus},
};


RenesasVisMessageHandler::RenesasVisMessageHandler(std::unique_ptr<OutputDevice> device):
    mDevice(device.release())
{

}

std::unique_ptr<VisMessage> 
RenesasVisMessageHandler::handle(const vis_string & msg)
{
    std::unique_ptr<VisMessage> vm;
    for (auto param : aosVisParameters)
    {
        auto value = param.getValue(param.paramName, msg);
        if(value != not_defined_value)
        {
            OutputParam prm {param.ctlIOId, value};
            *mDevice << prm;
            break;
        }
    }
    return vm;
}

int ValueHelper::getBool(const vis_string & propId, const vis_string & message)
{
    int res = not_defined_value;
    QByteArray br = message.toUtf8();

    QJsonDocument doc = QJsonDocument::fromJson(br);
    if(doc["value"].isObject() && doc["value"][propId].isBool())
    {
        res = (int)doc["value"][propId].toBool();
    }
    return res;
}
vis_string ValueHelper::getStringValue(const vis_string & propId, const vis_string & message)
{
    vis_string res;
    QByteArray br = message.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();
    QJsonArray arr = obj.value("value").toArray();
    foreach(const QJsonValue &v, arr){
        if(v.toObject().contains(propId)) {
           res = v.toObject().value(propId).toString();
       }
    }
    return res;
}
int ValueHelper::getTurnDirection(const vis_string & propId, const vis_string & message)
{
    Q_UNUSED(propId);
    auto value = getStringValue("Signal.Traffic.Turn.Direction", message);
    if(value == "right")
    {
       return 1;
    }
    else if(value == "left")
    {
        return 2;
    }
    return not_defined_value;
}
int ValueHelper::getValue(const vis_string & propId, const vis_string & message)
{
    int res = not_defined_value;
    QByteArray br = message.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();
    QJsonArray arr = obj.value("value").toArray();
    foreach(const QJsonValue &v, arr){
        if(v.toObject().contains(propId)) {
            res = (int)(v.toObject().value(propId).toInt());
            qDebug()<< propId  << " = " << res;
       }
    }
    return res;
}
int ValueHelper::getTireStatus(const vis_string & propId, const vis_string & message)
{
    int res = not_defined_value;
    QByteArray br = message.toUtf8();

    QJsonDocument doc = QJsonDocument::fromJson(br);
    if(doc["value"].isObject() && !doc["value"][propId].isUndefined())
    {
        res = doc["value"][propId].toInt();
        res = (int)(240 >= res);
    }
    return res;
}
int ValueHelper::getBeltStatus(const vis_string & propId, const vis_string & message)
{
    auto res = getBool(propId, message);
    if(res != not_defined_value)
    {
        res = !res;
    }
    return res;
}
