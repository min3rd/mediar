#ifndef FILE_H
#define FILE_H

#endif // FILE_H
#include <QObject>

class File : public QObject{
public:
    File(QString filePath){
        this->filePath = filePath;
    }
private:
    QString filePath;
}
