#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <receiver.h>
#include <mediacontroller.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine *engine;
    engine = new QQmlApplicationEngine(qApp);
    QQmlContext* context = engine->rootContext();

    Receiver receiver;
    MediaController mediaController;

    //add connecttion fro receiver to mediaController
    QObject::connect(&receiver,SIGNAL(playSignal()),&mediaController,SLOT(play()));
    QObject::connect(&receiver,SIGNAL(pauseSignal()),&mediaController,SLOT(pause()));

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    context->setContextProperty("receiver",&receiver);
    return app.exec();
}
