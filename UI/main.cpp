#include <QApplication>
#include "Link.h"
#include <QWebView>
#include <QWebFrame>

int main(int argc, char *argv[])
{
    Link::init();

    LinkObject *vo=Link::create("OutputVo");
    QVariantMap dataVo;
    dataVo["type"]="hdmi|vga";
    dataVo["mode"]=12;
    dataVo["ui"]=true;
    vo->start(dataVo);

    QApplication a(argc, argv);


    LinkObject *vi1=Link::create("InputVi","V1");
    QVariantMap viData;
    viData["interface"]="SDI-1";
    vi1->start(viData);

    LinkObject *vi2=Link::create("InputVi","V2");
    viData["interface"]="SDI-2";
    vi2->start(viData);

    LinkObject *mix=Link::create("MixV");
    QVariantMap dataMix;
    QVariantList srcs;
    srcs<<"V1"<<"V2";
    QVariantList layouts;
    QVariantMap lay;
    lay["x"]=0.1;
    lay["y"]=0.1;
    lay["w"]=0.6;
    lay["h"]=0.6;
    lay["a"]=1;
    lay["index"]=0;
    layouts<<lay;
    lay["x"]=0.5;
    lay["y"]=0.5;
    lay["w"]=0.3;
    lay["h"]=0.3;
    lay["a"]=1;
    lay["index"]=1;
    layouts<<lay;
    dataMix["src"]=srcs;
    dataMix["layout"]=layouts;
    mix->start(dataMix);

    vi1->linkV(mix);
    vi2->linkV(mix)->linkV(vo);

    QWebView web;
    QPalette pal = web.page()->palette();
    pal.setBrush(QPalette::Base, Qt::transparent);
    web.setPalette(pal);
    web.setAttribute(Qt::WA_TranslucentBackground, true);
    web.resize(1920,1080);
    web.show();
    web.settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
    web.load(QUrl("file:///root/demo/web/test.html"));

    web.page()->mainFrame()->addToJavaScriptWindowObject("mix", mix);

    return a.exec();
}
