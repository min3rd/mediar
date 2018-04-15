#include <receiver.h>
Receiver::Receiver(QObject *parent):QObject(parent){

}
QString Receiver::click(QString s){
    if(s.compare("play") == 0){
        return songList->getSongList()->at(i).filePath;
    }
    if(s.compare("pause") == 0){
        return "";
    }
    if(s.compare("next") == 0 || s.compare("tiếp theo") == 0){
        this->i++;
        if(this->i > songList->getSongList()->count() - 1)
            this->i = 0;
        return songList->getSongList()->at(i).filePath;
    }
    if(s.compare("pre") == 0 || s.compare("trở lại") == 0){
        this->i--;
        if(this->i < 0)
            this->i = songList->getSongList()->count() - 1;
        return songList->getSongList()->at(i).filePath;
    }
    if(s.compare("") != 0){
        qDebug() << s;
        this->i = s.toInt();
    }
    return s;
}
//void Receiver::setPath(QString path){

//}
