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
