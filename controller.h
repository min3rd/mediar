#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QThread>
#include <worker.h>
#include <QDir>
#include <qDebug>
#include <songlist.h>
#include <QQmlContext>
class Controller : public QObject
{
    Q_OBJECT
    QThread workerThread;
public:
    QDir dir;
    SongList *dataList;
    QQmlContext *context;
    Controller() {
        dir.setCurrent("music");
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Size | QDir::Reversed);
        Worker *worker = new Worker();
        worker->moveToThread(&workerThread);
        connect(this, SIGNAL(operate(QDir)), worker, SLOT(doWork(QDir)));
        connect(worker, SIGNAL(resultReady(Song*)), this, SLOT(handleResults(Song*)));
        connect(&workerThread, SIGNAL(finished()), worker, SLOT(doWork2()));
        workerThread.start();
    }
    ~Controller() {
        workerThread.quit();
        workerThread.wait();
    }
public slots:
    void handleResults(Song *song);
signals:
    void operate(QDir dir);
};
#endif // CONTROLLER_H
