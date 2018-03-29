#include <mediacontroller.h>
MediaController::MediaController(QObject *parent):QObject(parent){

}
void MediaController::play(){
    qDebug() << "Play";
}
