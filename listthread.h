#ifndef LISTTHREAD_H
#define LISTTHREAD_H
#include <QThread>
#include <QString>

class ListThread : public QThread{
public:
    QString name;
    void run();
};
#endif // LISTTHREAD_H
