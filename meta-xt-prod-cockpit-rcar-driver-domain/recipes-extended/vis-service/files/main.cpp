#include <QCoreApplication>
#include <QDebug>
#include <QtCore>
#include "VisClient.h"
#include <QTimer>
#include <QCommandLineOption>
#include <QCommandLineParser>

namespace{
const QCommandLineOption providerOption ("s", "The name of the service provider to use.", "service name [renesas,carla]");
const QCommandLineOption deviceOption ("d", "The name of the device to use.", "device name [taurus]");
const QCommandLineOption urlOption ("u", "The name of the aos-vis url to use.", "url, default Default wwwivi:443");
const QCommandLineOption pathOption ("p", "The path to the device.", "path to the device:/dev/taurus ");
};

struct ClientParameters
{
    QString provider;
    QString device;
    QString url;
    QString devicePath;
};

void initParams(QCommandLineParser& parser, ClientParameters & params)
{
    if (parser.isSet(providerOption)) {
            qDebug() << "Provider name : " << parser.value(providerOption);
            params.provider = parser.value(providerOption);
    }
    if (parser.isSet(deviceOption)) {
            qDebug() << "Device name : " << parser.value(deviceOption);
            params.device = parser.value(deviceOption);
    }
    if (parser.isSet(urlOption)) {
            qDebug() << "URL : " << parser.value(urlOption);
            params.url = parser.value(urlOption);
    }
    if (parser.isSet(pathOption)) {
            qDebug() << "Path : " << parser.value(pathOption);
            params.devicePath = parser.value(pathOption);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QString rpmsg("/dev/cluster-taurus");
    //QString provider = "renesas";
 /*   if(argc > 3){
	   rpmsg = argv[3];
    }
    else if(argc > 2){
        provider = "argv[2]"
    }
*/
    QCommandLineParser parser;
    parser.addOption(providerOption);
    parser.addOption(deviceOption);
    parser.addOption(urlOption);
    parser.addOption(pathOption);
    parser.addHelpOption();

    parser.process(a);

    qDebug() << "Working ...";

    //QString url = argc > 1 ? argv[1] : "wss://wwwivi:8088";
    ClientParameters params {
        "renesas",
        "taurus",
        "wwwivi:443",
        "/dev/cluster-taurus"
    };
    initParams(parser, params);
    qDebug() << "Used parameters";
    qDebug() << "Provider: " << params.provider << " "
             << "Device: " << params.device << " " 
             << "Url: " << params.url << " "
             << "Device path: " << params.devicePath;

    VisClient visClient(&a,
                       params.url,
                       params.provider,
                       params.device,
                       params.devicePath
                       );

    visClient.connectTo();

    return a.exec();
}
