#ifdef TESTING
#include <iostream>
#endif
class Base;

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
public:
    // constructor
    LinkedList();
    // This prepends a new value at the beginning of the list
    void addValue(Base* val);

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    Base* popValue();
};
