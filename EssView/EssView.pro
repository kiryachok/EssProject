#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:30:14
#
#-------------------------------------------------

QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EssView
TEMPLATE = lib

DEFINES += ESSVIEW_LIBRARY

SOURCES += essview.cpp \
    mainwindow.cpp

HEADERS += essview.h\
        essview_global.h \
    mainwindow.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    mainwindow.ui

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
