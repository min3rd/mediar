#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
QString Receiver::click(QString s){
    if(s.compare("play") == 0){
        if(dataList.length() > 0){
            if(playing){
                playing = false;
                return "pause";
            }else{
                playing = true;
                return this->dataList.at(this->index);
            }
        }
        return "";
    }
    if(s.compare("next") == 0){
        if(!loop)
            index++;
        if(index > dataList.length() - 1){
            index = 0;
        }
        return dataList.at(index);
    }
    if(s.compare("previous") == 0){
        if(!loop)
            index--;
        if(index <0){
            index = dataList.length() - 1;
        }
        return dataList.at(index);
    }
    if(s.compare("loop") == 0){
        if(loop){
            loop = false;
        }else{
            loop = true;
        }
    }
    return "stop";
}
void Receiver::setPath(QString path){

}
bool Receiver::addFile(QString path){
    this->dataList.append(path);
    this->context->setContextProperty("dataList",this->dataList);
    return true;
}
