CONFIG += c++17
QT += core quickcontrols2 websockets dbus
DEFINES -= QT_NO_SSL
HEADERS += VisClient.h \
    providers/include/Renesas.h \
    devices/include/TaurusOutputDevice.h \
    VisServiceClient.h
SOURCES += main.cpp \
    providers/sources/Renesas.cpp \
    devices/sources/TaurusOutputDevice.cpp \
    VisClient.cpp
