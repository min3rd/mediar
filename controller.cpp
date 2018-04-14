#include <controller.h>
#include <QDebug>
void Controller::handleResults(Song *song){
    this->dataList->addEvent(*song);
    context->setContextProperty("dataList",this->dataList);
}
