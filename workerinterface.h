#ifndef WORKERINTERFACE_H
#define WORKERINTERFACE_H

#include <QObject>
#include <QThread>
#include <worker.h>

class WorkerInterface : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString data READ getData NOTIFY dataChanged)
public:
    WorkerInterface() : mWorker(mData) {
        mWorker.moveToThread(&mThread);
        connect(this, &WorkerInterface::process, &mWorker, &Worker::process);
        connect(&mWorker, &Worker::processFinished, [this]{
            qDebug() << "ProcessFinished in  : " << QThread::currentThreadId();
            emit dataChanged();
        });

        mThread.start();
    }

    QString getData() const {
        return mData;
    }

    ~WorkerInterface() {
        mThread.exit();
        mThread.wait();
    }

signals:
    void dataChanged();
    void process();

private:
    QThread mThread;
    QString mData;
    Worker mWorker;
};
#endif // WORKERINTERFACE_H
