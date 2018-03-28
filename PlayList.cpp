#include <node.h>
#include <file.h>
class PlayList : public QObject{
public:
    PlayList(){
        head = null;
        currentNode = head;
    }
    void add(File file);
    bool remove(int i);
    void play(int i);
    void pause(int i);
    int size();
private:
    Node currentNode;
    Node head;

signals:

};
bool PlayList::add(File file){
    Node node = new Node(file, null);
    if(head==null){
        head = node;
    }else{
        currentNode.setNext(node);
        currentNode = node;
    }
    return true;
}
bool PlayList::remove(int i){
    if(i>this->size()-1){
        return false;
    }
    Node node = this->head;
    for(int j = 1; j< this->size();j++){
        if(j==i){
            Node temp = node.next;
            node.next = temp.next;
        }else{
            node = node.next;
        }
    }
    return true;
}
void PlayList::size(){
    int i = 0;
    Node temp = this->head;
    while( temp != null ){
        temp = temp.next;
        i++;
    }
    return i;
}
