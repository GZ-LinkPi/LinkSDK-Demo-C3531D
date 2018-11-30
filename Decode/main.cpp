#include <QCoreApplication>
#include "Link.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi|vga";
    dataVo["mode"]=12;
    dataVo["ui"]=true;
    vo->start(dataVo);

    LinkObject *net=Link::create("InputNet");
    QVariantMap netData;
    netData["path"]="rtmp://192.168.1.218/live/stream0";
    net->start(netData);

    LinkObject *dec=Link::create("DecodeV");
    dec->start();

    net->linkV(dec)->linkV(vo);

    return a.exec();
}

