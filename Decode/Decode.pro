QT += core
QT -= gui

TARGET = Decode
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

chip=HI3531D
include(../../../LinkLib/Link.pri)
DESTDIR +=../bin


SOURCES += main.cpp

