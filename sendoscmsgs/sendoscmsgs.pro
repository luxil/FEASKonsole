#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T20:13:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sendoscmsgs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ip/UdpSocket.cpp \
    osc/OscOutboundPacketStream.cpp \
    ip/IpEndpointName.cpp \
    ip/NetworkingUtils.cpp \
    osc/OscTypes.cpp \
    sendoscmsg.cpp

HEADERS  += mainwindow.h \
    ip/UdpSocket.h \
    osc/OscOutboundPacketStream.h \
    ip/IpEndpointName.h \
    ip/NetworkingUtils.h \
    ip/PacketListener.h \
    ip/TimerListener.h \
    osc/OscException.h \
    osc/OscHostEndianness.h \
    osc/OscTypes.h \
    sendoscmsg.h

FORMS    += mainwindow.ui

DISTFILES +=
