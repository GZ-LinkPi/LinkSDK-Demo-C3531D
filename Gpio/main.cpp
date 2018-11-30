#include <QCoreApplication>
#include "Link.h"
#include "Gpio.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init(false);
    Gpio gpio;
    gpio.init();

    return a.exec();
}
