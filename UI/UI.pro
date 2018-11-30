QT += core gui webkit webkitwidgets

TARGET = UI
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

chip=HI3531D
include(../../../LinkLib/Link.pri)
DESTDIR +=../bin

SOURCES += main.cpp

