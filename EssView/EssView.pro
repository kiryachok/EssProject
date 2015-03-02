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
    mainwindow.cpp \
    changemoddialog.cpp \
    newmoddialog.cpp \
    prmoddialog.cpp \
    attrwindow.cpp \
    newattrwindow.cpp \
    launchconditions.cpp

HEADERS += essview.h\
        essview_global.h \
    mainwindow.h \
    changemoddialog.h \
    newmoddialog.h \
    prmoddialog.h \
    attrwindow.h \
    newattrwindow.h \
    launchconditions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    mainwindow.ui \
    changemoddialog.ui \
    newmoddialog.ui \
    prmoddialog.ui \
    attrwindow.ui \
    newattrwindow.ui \
    launchconditions.ui

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
LIBS   += -L"$$OUTPUT_DIR/bin/" -lEssController
