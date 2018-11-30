#include <QCoreApplication>
#include "Link.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Link::init();

    LinkObject *vi=Link::create("InputVi");
    QVariantMap dataVi;
    dataVi["interface"]="HDMI-1";
    vi->start(dataVi);

    LinkObject *ai=Link::create("InputAi");
    QVariantMap dataAi;
    dataAi["interface"]="HDMI-1";
    ai->start(dataAi);

    LinkObject *encv=Link::create("EncodeV");
    QVariantMap dataEncV;
    dataEncV["bitrate"]=2000;
    dataEncV["width"]=1280;
    dataEncV["height"]=720;
    encv->start(dataEncV);

    LinkObject *enca=Link::create("EncodeA");
    enca->start();

    LinkObject *mux=Link::create("Mux");
    QVariantMap dataMux;
    dataMux["path"]="/tmp/test.mp4";

    vi->linkV(encv)->linkV(mux);
    ai->linkA(enca)->linkA(mux);

    mux->start(dataMux);
    sleep(8);
    mux->stop();


    return a.exec();
}
