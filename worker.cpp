#include <worker.h>
#include <QDebug>
void Worker::doWork(QDir dir){
    qDebug()<<"Hello World";
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list[i];
        Song song;
        song.id = i;
        song.name = fileInfo.fileName();
        song.filePath=fileInfo.absoluteFilePath();
        emit resultReady(&song);
    }
}
void Worker::doWork2(){
    qDebug()<<"Hello World";
    QDir dir;
    dir.setCurrent("music");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Size | QDir::Reversed);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i) {
        QFileInfo fileInfo = list[i];
        Song song;
        song.id = i;
        song.name = fileInfo.fileName();
        song.filePath=fileInfo.absoluteFilePath();
        emit resultReady(&song);
    }
}
void Worker::updateList(){
    qDebug()<<"Updating";
}
