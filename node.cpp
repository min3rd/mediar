#include <QObject>
class Node : public QObject{
private:
    File file;
    Node next;
public slots:
    void add(Node node);
}
void Node::add(Node node){
    this->next = node;
}
