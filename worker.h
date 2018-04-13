#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include <QDir>
#include <song.h>
class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork(QDir dir);
    void doWork2();
    void updateList();

signals:
    void resultReady(Song *song);
};
#endif // WORKER_H
