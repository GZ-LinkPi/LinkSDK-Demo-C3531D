#include "Gpio.h"
#include <QDebug>

Gpio::Gpio(QObject *parent) : QObject(parent)
{

}

void Gpio::init()
{
    gpio=Link::create("GPIO");
    gpio->start();
    if(gpio->invoke("registEvent","GPIO15_0").toBool())
    {
        connect(gpio,SIGNAL(newEvent(QString,QVariant)),this,SLOT(onGPIO(QString,QVariant)));
    }

}

void Gpio::onGPIO(QString type, QVariant info)
{
    QString name=info.toString();
    qDebug()<<name<<type;
}
