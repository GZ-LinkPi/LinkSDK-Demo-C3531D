#include <QCoreApplication>
#include "Link.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    LinkObject *mix=Link::create("MixV");
    QVariantMap dataMix;
    QVariantList srcs;
    QVariantList layouts;

    for(int i=0;i<9;i++)
    {
        QVariantMap lay;
        lay["x"]=1.0*(i%3)/3;
        lay["y"]=1.0*(i/3)/3;
        lay["w"]=1.0/3;
        lay["h"]=1.0/3;
        lay["a"]=1;
        lay["index"]=i;
        layouts<<lay;
    }

    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi|vga";
    dataVo["mode"]=12;
    dataVo["ui"]=true;
    vo->start(dataVo);

    QList<LinkObject *> inputList;
    for(int i=1;i<=4;i++)
    {
        QString iface="SDI-"+QString::number(i);
        LinkObject *vi=Link::create("InputVi");
        QVariantMap data;
        data["interface"]=iface;
        vi->start(data);
        inputList<<vi;
    }

    for(int i=1;i<=3;i++)
    {
        QString iface="HDMI-"+QString::number(i);
        LinkObject *vi=Link::create("InputVi");
        QVariantMap data;
        data["interface"]=iface;
        vi->start(data);
        inputList<<vi;
    }

    {
        LinkObject *vi=Link::create("InputVi");
        QVariantMap data;
        data["interface"]="AHD";
        vi->start(data);
        inputList<<vi;
    }

    {
        LinkObject *usb=Link::create("InputV4l2");
        usb->start();
        LinkObject *dec=Link::create("DecodeV");
        dec->start();
        usb->linkV(dec);
        inputList<<dec;
    }

    for(int i=0;i<inputList.count();i++)
    {
        srcs<<inputList[i]->name();
        inputList[i]->linkV(mix);
    }

    dataMix["src"]=srcs;
    dataMix["layout"]=layouts;
    mix->start(dataMix);
    mix->linkV(vo);

    {
        LinkObject *mixA=Link::create("MixA");
        for(int i=1;i<=3;i++)
        {
            LinkObject *ai=Link::create("InputAi");
            QVariantMap aiData;
            aiData["interface"]="HDMI-"+QString::number(i);
            ai->start(aiData);
            if(i==1)
            {
                QVariantMap dataMixA;
                dataMixA["main"]=ai->name();
                mixA->start(dataMixA);
            }
            ai->linkA(mixA);
        }

        LinkObject *ao=Link::create("OutputAo");
        QVariantMap aoData;
        aoData["interface"]="HDMI-OUT";
        ao->start(aoData);
        mixA->linkA(ao);
    }

    return a.exec();
}

