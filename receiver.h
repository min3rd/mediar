#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QDebug>

class Receiver : public QObject{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);
signals:
    void playSignal();
    void nextSignal();
    void previousSignal();
    void pauseSignal();
public slots:
    void click(QString s);
};
#endif // RECEIVER_H
