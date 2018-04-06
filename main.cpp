#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <receiver.h>
#include <song.h>
#include <QDir>
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine;
    engine = new QQmlApplicationEngine(qApp);
    QQmlContext* context = engine->rootContext();

    Receiver receiver;
    QStringList dataList;
    QDir dir;
    dir.setCurrent("music");
    receiver.dir = dir;
    receiver.dataList = dataList;
    receiver.context = context;
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list.at(i);
        dataList.append(fileInfo.fileName());
    }

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    context->setContextProperty("receiver",&receiver);
    context->setContextProperty("dataList",QVariant::fromValue(dataList));
    context->setContextProperty("folderPath",dir.absolutePath());
    return app.exec();
}
