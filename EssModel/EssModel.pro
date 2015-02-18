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

CONFIG(debug, debug|release): {
    OUTPUT_DIR = "$$PWD/../../buildEss/debug"
} else: {
    OUTPUT_DIR = "$$PWD/../../buildEss/release"
}

UI_DIR      = "$$OUTPUT_DIR/ui/"
MOC_DIR     = "$$OUTPUT_DIR/moc/"
RCC_DIR     = "$$OUTPUT_DIR/res/"
DESTDIR     = "$$OUTPUT_DIR/bin/"
OBJECTS_DIR = "$$OUTPUT_DIR/obj/"
