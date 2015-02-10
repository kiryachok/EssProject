#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:29:24
#
#-------------------------------------------------

QT       -= gui

TARGET = EssModel
TEMPLATE = lib

DEFINES += ESSMODEL_LIBRARY

SOURCES += essmodel.cpp

HEADERS += essmodel.h\
        essmodel_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
