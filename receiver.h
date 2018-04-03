#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QDebug>
#include <mediacontroller.h>

class Receiver : public QObject{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);
signals:
    void playSignal();
    void changeSignal(int i);
    void pauseSignal();
public slots:
    QString click(QString s);
};
#endif // RECEIVER_H
