#include <QtTest>
#include <QObject>
#include <QSharedPointer>
#include "../visclient.h"
#include "../VisSocket.h"

class UnitTestSocket : public VisWebSocket
{
public:
    void receivedText(const QString & message)
    {
        textMessageReceived(message);
    }
protected:
    void onOpen(const QUrl &url) override{
        Q_UNUSED(url);
        connected();
    };
    void onClose() override{
        disconnected();
    };
    void onSendTextMessage(const QString &message) override{
        Q_UNUSED(message);
    };
};

// add necessary includes here

class cluster_view_input : public QObject
{
    Q_OBJECT

public:
    cluster_view_input();
    ~cluster_view_input();

private slots:
    void test_set_speed();
    void test_set_gear();
    void test_set_rpm();
    void test_set_battery();
    void test_set_turn();
    void test_set_all();
};

static const QString msg_subscr = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[] \
                                }";
static const QString msg_speed = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Vehicle.Speed\":21000}] \
                                }";
static const QString msg_gear = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.Transmission.Gear\":3}] \
                                }";
static const QString msg_gear_rev = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.Transmission.Gear\":-1}] \
                                }";
static const QString msg_gear_park = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.Transmission.Gear\":0}] \
                                }";
static const QString msg_gear_neutral = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.Transmission.Gear\":2}] \
                                }";
static const QString msg_rpm = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.InternaCombustionEngine.Engine.Speed\":3000}] \
                                }";
static const QString msg_battery = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Drivetrain.BatteryManagement.BatteryCapacity\":70}] \
                                }";
static const QString msg_turn_left = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Traffic.Turn.Direction\":\"left\"}] \
                                }";
static const QString msg_turn_right = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Traffic.Turn.Direction\":\"right\"}] \
                                }";
static const QString msg_all = "{ \
                                  \"action\":\"subscription\", \
                                  \"subscriptionId\":\"1\", \
                                  \"value\":[{\"Signal.Traffic.Turn.Direction\":\"right\"}, \
                                  {\"Signal.Drivetrain.BatteryManagement.BatteryCapacity\":70}, \
                                  {\"Signal.Drivetrain.InternaCombustionEngine.Engine.Speed\":3000}, \
                                  {\"Signal.Drivetrain.Transmission.Gear\":3}, \
                                  {\"Signal.Vehicle.Speed\":21000} \
                                  ] \
                                }";
cluster_view_input::cluster_view_input()
{

}

cluster_view_input::~cluster_view_input()
{

}

void cluster_view_input::test_set_speed()
{
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_speed);
    auto speed = client.speedValue();
    QCOMPARE(speed, 21);
    socket->close();
}

void cluster_view_input::cluster_view_input::test_set_gear()
{
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_gear);
    auto gear = client.gearValue();
    QCOMPARE(gear, 3);

    socket->receivedText(msg_gear_park);
    gear = client.gearValue();
    QCOMPARE(gear, 0);

    socket->receivedText(msg_gear_neutral);
    gear = client.gearValue();
    QCOMPARE(gear, 2);

    socket->receivedText(msg_gear_rev);
    gear = client.gearValue();
    QCOMPARE(gear, 5);

    socket->close();
}

void cluster_view_input::test_set_rpm()
{
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_rpm);
    auto rpm = client.rpmValue();
    QCOMPARE(rpm, 3000);
    socket->close();
}
void cluster_view_input::test_set_battery()
{
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_battery);
    auto battery = client.batteryValue();
    QCOMPARE(battery, 70);
    socket->close();
}
void cluster_view_input::test_set_turn()
{
    // 1: right
    // 2: left
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_turn_left);
    auto turn = client.turnValue();
    QCOMPARE(turn, 2);
    socket->receivedText(msg_turn_right);
    turn = client.turnValue();
    QCOMPARE(turn, 1);
    socket->close();
}
void cluster_view_input::test_set_all()
{
    QSharedPointer<UnitTestSocket> socket(new UnitTestSocket());
    VisClient client(socket);
    QUrl url;
    socket->open(url);
    socket->receivedText(msg_subscr);// just initial communication
    socket->receivedText(msg_subscr);
    socket->receivedText(msg_all);
    auto turn = client.turnValue();
    QCOMPARE(turn, 1);
    auto battery = client.batteryValue();
    QCOMPARE(battery, 70);
    auto gear = client.gearValue();
    QCOMPARE(gear, 3);
    auto rpm = client.rpmValue();
    QCOMPARE(rpm, 3000);
    auto speed = client.speedValue();
    QCOMPARE(speed, 21);
    socket->close();
}

QTEST_APPLESS_MAIN(cluster_view_input)

#include "tst_cluster_view_input.moc"
