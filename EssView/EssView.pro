#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:30:14
#
#-------------------------------------------------

QT       -= gui

TARGET = EssView
TEMPLATE = lib

DEFINES += ESSVIEW_LIBRARY

SOURCES += essview.cpp

HEADERS += essview.h\
        essview_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
