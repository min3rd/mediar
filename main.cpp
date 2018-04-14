#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <receiver.h>
#include <song.h>
#include <QDir>
#include <iostream>
#include <QTranslator>
#include <QThread>
#include <QAbstractListModel>
#include <songlist.h>
#include <readfolder.h>
#include <controller.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine *engine;
    engine = new QQmlApplicationEngine(qApp);
    QQmlContext* context = engine->rootContext();

    Receiver receiver;
    receiver.a = app;
//    SongList *dataList = new SongList();
    QDir dir;
    dir.setCurrent("music");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);
//    ReadFolder reader;
//    reader.dir = dir;
//    QObject::connect(&reader,SIGNAL(sendInfo(Song&)),dataList,SLOT(addEvent(Song&)));
//    reader.start();
//    QFileInfoList list = dir.entryInfoList();
//    for (int i = 0; i < list.size(); ++i) {
//        QFileInfo fileInfo = list[i];
//        Song *song = new Song();
//        song->name = fileInfo.fileName();
//        song->filePath=fileInfo.absoluteFilePath();
//        dataList->addEvent(*song);
//    }
    Controller controller;
    controller.context = context;
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    context->setContextProperty("receiver",&receiver);
//    context->setContextProperty("dataList",controller.dataList);
    return app.exec();
}
