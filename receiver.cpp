#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
void Receiver::click(QString s){
    if(!s.compare("play")){
        qDebug() << "Play";
        emit playSignal();
        return;
    }
    if(!s.compare("next")){
        qDebug() << "Next";
        emit changeSignal(1);
        return;
    }
    if(!s.compare("previous")){
        qDebug() << "Previous";
        emit changeSignal(-1);
        return;
    }
    if(!s.compare("pause")){
        qDebug() << "Pause";
        emit pauseSignal();
        return;
    }
    if(!s.compare("mute")){
        qDebug() << "Mute";
        return;
    }
    if(!s.compare("unmute")){
        qDebug() << "Unmute";
        return;
    }
    qDebug()<<s;
}
