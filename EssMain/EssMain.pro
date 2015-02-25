#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T09:31:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EssMain
TEMPLATE = app


SOURCES += main.cpp

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

INCLUDEPATH += "../EssView/"

LIBS   += -L"$$OUTPUT_DIR/bin/" -lEssView
LIBS   += -L"$$OUTPUT_DIR/bin/" -lEssModel
