#ifndef READFOLDER_H
#define READFOLDER_H
#include <QThread>
#include <QDir>
#include <song.h>
class ReadFolder: public QThread{
public:
    void run();
    QDir dir;
signals:
    void sendInfo(Song &song);
};
#endif // READFOLDER_H
