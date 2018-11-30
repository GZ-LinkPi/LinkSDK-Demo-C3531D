QT += core
QT -= gui

TARGET = Gpio
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

chip=HI3531D
include(../../../LinkLib/Link.pri)
DESTDIR +=../bin

SOURCES += main.cpp \
    Gpio.cpp

HEADERS += \
    Gpio.h

