#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <receiver.h>
#include <song.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine *engine;
    engine = new QQmlApplicationEngine(qApp);
    QQmlContext* context = engine->rootContext();

    Receiver receiver;

   QStringList dataList;
   dataList.append("Song 1");
   dataList.append("Song 2");
   dataList.append("Song 3");
   dataList.append("Song 4");

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    context->setContextProperty("receiver",&receiver);
    context->setContextProperty("dataList",QVariant::fromValue(dataList));
    return app.exec();
}
