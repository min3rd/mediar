#include <songlist.h>

SongList::SongList(QObject *parent):QAbstractListModel(parent){

}
SongList::~SongList(){

}
QHash<int,QByteArray> SongList::roleNames() const{
    QHash<int,QByteArray> roleNames;
    roleNames[idRole] ="id";
    roleNames[nameRole] = "name";
    roleNames[filePathRole] = "filePath";
    return roleNames;
}
int SongList::rowCount(const QModelIndex &parent) const{
    return mSonglist.count();
}
QVariant SongList::data(const QModelIndex &index, int role) const{
    if (index.row() < 0 || index.row() >= mSonglist.count())
    {
        return QVariant();
    }
    QVariant text;

      if(role == idRole)
      {
          Song song = mSonglist[index.row()];
          text = song.id;
      }
      else if(role == nameRole)
      {
          Song song = mSonglist[index.row()];
          text = song.name;
      }else{
          Song song = mSonglist[index.row()];
          text=song.filePath;
      }
      return text;
}
void SongList::addEvent(Song &song){
    beginInsertRows(QModelIndex(),0,0);
    mSonglist.append(song);
    endInsertRows();
}
QList<Song>* SongList::getSongList(){
    return &mSonglist;
}
