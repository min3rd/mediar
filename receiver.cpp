#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
void Receiver::click(QString s){
    if(!s.compare("play")){
        qDebug() << "Play";
        emit playSignal();
    }
    if(!s.compare("next")){
        qDebug() << "Next";
        emit changeSignal(1);
    }
    if(!s.compare("previous")){
        qDebug() << "Previous";
        emit changeSignal(-1);
    }
    if(!s.compare("pause")){
        qDebug() << "Pause";
        emit pauseSignal();
    }
    if(!s.compare("mute")){
        qDebug() << "Mute";
    }
    if(!s.compare("unmute")){
        qDebug() << "Unmute";
    }
}
