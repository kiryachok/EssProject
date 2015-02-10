#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:30:40
#
#-------------------------------------------------

QT       -= gui

TARGET = EssController
TEMPLATE = lib

DEFINES += ESSCONTROLLER_LIBRARY

SOURCES += esscontroller.cpp

HEADERS += esscontroller.h\
        esscontroller_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
