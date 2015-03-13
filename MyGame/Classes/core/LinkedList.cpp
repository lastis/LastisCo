#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    head = NULL; // set head to NULL
}

// This prepends a new value at the beginning of the list
void LinkedList::addValue(Base* val){
    Node *n = new Node();   // create new Node
    n->val = val;           // set value
    n->next = head;         // make the node point to the next node.
                            //  If the list is empty, this is NULL, 
                            // so the end of the list --> OK
    head = n;               // last but not least, make the head 
                            // point at the new node.
}

// returns the first element in the list and deletes the Node.
// caution, no error-checking here!
Base* LinkedList::popValue(){
    Node* n = head;
    Base* val = n->val;

    head = head->next;
    delete n;
    return val;
}

