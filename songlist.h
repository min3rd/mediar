#ifndef SONGLIST_H
#define SONGLIST_H
#include <QAbstractListModel>
#include <song.h>

class SongList:public QAbstractListModel{
    Q_OBJECT
public:
    enum songEventRoles{
        idRole,
        nameRole,
        filePathRole};
    SongList(QObject *parent=0);
    ~SongList();
    int rowCount(const QModelIndex &parent) const;
    QHash<int,QByteArray> SongList::roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    QList<Song>* getSongList();
public slots:
    void addEvent(Song &song);
private:
    QList<Song> mSonglist;
};
#endif // SONGLIST_H
