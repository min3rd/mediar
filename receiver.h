#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QDebug>
#include <mediacontroller.h>
#include <QDir>
#include <QQmlContext>

class Receiver : public QObject{
    Q_OBJECT
public:
    int index = 0;
    bool loop = false;
    bool mute = false;
    bool playing = false;
    QStringList dataList;
    QQmlContext* context;
    explicit Receiver(QObject *parent = 0);
public slots:
    QString click(QString s);
    void setPath(QString path);
    bool addFile(QString path);
};
#endif // RECEIVER_H
