#include <controller.h>
#include <QDebug>
void Controller::handleResults(Song *song){
    this->dataList->addEvent(*song);
    this->context->setContextProperty('dataList',this->dataList);
}
