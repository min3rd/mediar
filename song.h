#ifndef SONG_H
#define SONG_H
#include <QObject>
class Song : public QObject{
//Q_OBJECT
    //Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    //Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
public:
    QString a;
    QString b;
    Song(QString name,QString color);
};
#endif // SONG_H
