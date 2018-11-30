QT += core
QT -= gui

TARGET = Encode
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

chip=HI3531D
#HOME=/home/zc
#CROSS=$$HOME/cross/v300
#MPP=$$HOME/3531A/SDK/Hi3531A_SDK_V1.0.4.0/mpp
include(../../../LinkLib/Link.pri)
DESTDIR +=../bin

SOURCES += main.cpp

