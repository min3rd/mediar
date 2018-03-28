#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
void Receiver::click(QString s){
    if(s.compare("play")){
        emit this->playSignal();
    }
}
