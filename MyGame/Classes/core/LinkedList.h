#ifdef TESTING
#include <iostream>
#endif
#include "Base.h"

class LinkedList{
    // Struct inside the class LinkedList
    // This is one node which is not needed by the caller. It is just
    // for internal work.
    struct Node {
        Base *val;
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
    void add(Base* val);
    bool isEmpty();
    int getLength();
    Base* findWithLabel(int label);
    bool removeWithLabel(int label);

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    Base* pop();
};
