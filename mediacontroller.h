#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H
#include <QObject>

class MediaController : public QObject{
public slots:
    void play();
    void pause();
    void change(int i);
};
#endif // MEDIACONTROLLER_H
