#include <QCoreApplication>
#include "Link.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi";
    dataVo["mode"]=32;
    dataVo["ui"]=true;
    vo->start(dataVo);

    LinkObject *vi=Link::create("InputVi");
    QVariantMap viData;
    viData["interface"]="HDMI-1";
    vi->start(viData);

    LinkObject *encV=Link::create("EncodeV");
    QVariantMap encData;
    encData["width"]=3840;
    encData["height"]=2160;
    encData["bitrate"]=15000;
    encData["codec"]="h264";
    encV->start(encData);

    LinkObject *ai=Link::create("InputAi");
    QVariantMap aiData;
    aiData["interface"]="HDMI-1";
    ai->start(aiData);

    LinkObject *encA=Link::create("EncodeA");
    encA->start();

    LinkObject *mux=Link::create("Mux");
    QVariantMap dataMux;
    dataMux["path"]="rtmp://127.0.0.1/live/test";
    mux->start(dataMux);

    ai->linkA(encA)->linkA(mux);
    vi->linkV(encV)->linkV(mux);
    vi->linkV(vo);

    return a.exec();
}

