#ifdef TESTING
#include <iostream>
#endif
#include "objects/Object.h"

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        Object *val;
        Node *next;
    };
private:
    Node *head; 
    int length;
public:
    LinkedList();
    ~LinkedList();
    void    add(Object& val);
    void    deleteObjects();
    bool    isEmpty();
    int     getLength();
    Object* findWithUID(int UID);
    Object* findWithID(int ID);
    Object* findWithIndex(int i);
    Object* popWithUID(int UID);
    Object* popWithID(int ID);
    Object* pop();

};
