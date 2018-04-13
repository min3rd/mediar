#include <listthread.h>
#include <QDebug>

void ListThread::run(){
    for(int i = 100;i>0;i--){
        qDebug()<<this->name<<" : " <<i;
    }
}
