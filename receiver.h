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
    QDir dir;
    QStringList dataList;
    QQmlContext* context;
    explicit Receiver(QObject *parent = 0);
public slots:
    QString click(QString s);
    void setPath(QString path);
};
#endif // RECEIVER_H
