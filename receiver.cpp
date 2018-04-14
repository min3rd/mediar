#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
QString Receiver::click(QString s){
    if(s.compare('vietnameses') == 0){
        this->t.load(":/libs/qm/vietnamese.qm");
        this->a.installTranslator(&t);
    }
    return s;
}
void Receiver::setPath(QString path){

}
