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
    // constructor
    LinkedList();
    ~LinkedList();
    // This prepends a new value at the beginning of the list
    void add(Object& val);
    bool isEmpty();
    int getLength();
    Object* findWithUID(int UID);
    bool removeWithUID(int UID);
    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    Object* pop();

};
