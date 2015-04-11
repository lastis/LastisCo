#include <iostream>
#include "objects/Item.h"

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        Item *val;
        Node *next;
    };
private:
    Node *head; 
    int length;
public:
    LinkedList();
    ~LinkedList();
    void    add(Item& val);
    void    deleteItems();
    bool    isEmpty();
    int     getLength();
    Item* findWithUID(int UID);
    Item* findWithID(int ID);
    Item* findWithIndex(int i);
    Item* popWithUID(int UID);
    Item* popWithID(int ID);
    Item* pop();

};
