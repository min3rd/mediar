#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
QString Receiver::click(QString s){
    return s;
}
