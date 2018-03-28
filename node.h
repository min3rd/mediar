#ifndef NODE_H
#define NODE_H

#endif // NODE_H
#include <QObject>
#include <file.h>

class Node{
public:
    Node(File file,Node next){
        this->file = file;
        this->next = next;
    }
    void setNext(Node node);
private:
    File file;
    Node next;
};
void Node::setNext(Node node){
    this->next = node;
}
