#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:30:40
#
#-------------------------------------------------

QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EssController
TEMPLATE = lib

DEFINES += ESSCONTROLLER_LIBRARY

SOURCES += \
    mapattributecontroller.cpp \
    attributecontroller.cpp \
    prmodcontroller.cpp \
    projectcontroller.cpp \
    cmapstrategiescontroller.cpp

HEADERS +=\
        esscontroller_global.h \
    mapattributecontroller.h \
    attributecontroller.h \
    prmodcontroller.h \
    projectcontroller.h \
    cmapstrategiescontroller.h

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

INCLUDEPATH += "../EssModel/"

LIBS   += -L"$$OUTPUT_DIR/bin/" -lEssModel
