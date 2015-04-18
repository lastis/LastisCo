#ifndef __LINKED_LIST_H_INCLUDED__
#define __LINKED_LIST_H_INCLUDED__
#include <iostream>
#include "Item.h"

class ShipMaster;
class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        Item *val = NULL;
        Node *next = NULL;
    };
private:
    Node *head; 
    int length;
public:
    LinkedList();
    ~LinkedList();
    void    add(Item* val);
    bool    isEmpty();
    int     getLength();
    void    update(ShipMaster& ship);
    Item*   findWithUID(int UID);
    Item*   findWithID(int ID);
    Item*   findWithIndex(int i);
    Item*   popWithUID(int UID);
    Item*   popWithID(int ID);
    Item*   pop();

};
#endif
