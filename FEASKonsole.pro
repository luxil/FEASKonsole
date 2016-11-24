#QT += core
#QT -= gui
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = FEASKonsole
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp\
dlib-19.2/dlib/all/source.cpp\
    facedetandfpl.cpp \
    win.cpp


INCLUDEPATH += dlib-19.2
QMAKE_CXXFLAGS_RELEASE += /arch:AVX
include(../opencv/videoengine.pri)

#LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
#LIBS+= -lgdi32 -lcomctl32 -luser32 -lwinmm -lws2_32
#INCLUDEPATH += "C:\dlib_build\include"
#LIBS += -L"C:\dlib_build\lib"
#LIBS += -ldlib
#QMAKE_CXXFLAGS += -DDLIB_JPEG_SUPPORT

HEADERS += \
    facedetandfpl.h \
    win.h
