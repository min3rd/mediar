#ifndef LIST_H
#define LIST_H

#endif // LIST_H
#include <node.h>

class List{

public:
    List(){
        head = null;
        currentNode = head;
    }
    void add(File file);
    bool remove(int i);
    int size();
private:
    Node currentNode;
    Node head;
};
bool List::add(File file){
    Node node = new Node(file, null);
    if(head==null){
        head = node;
    }else{
        currentNode.setNext(node);
        currentNode = node;
    }
    return true;
}
bool List::remove(int i){
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
void List::size(){
    int i = 0;
    Node temp = this->head;
    while( temp != null ){
        temp = temp.next;
        i++;
    }
    return i;
}
