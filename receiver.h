#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QDebug>
#include <mediacontroller.h>
#include <QDir>
#include <QQmlContext>
#include <QTranslator>
#include <QGuiApplication>
#include <songlist.h>

class Receiver : public QObject{
    Q_OBJECT
public:
    int i = 0;
    SongList *songList;
    QTranslator *t;
//    QGuiApplication a;
    explicit Receiver(QObject *parent = 0);
public slots:
    QString click(QString s);
//    void setPath(QString path);
};
#endif // RECEIVER_H
