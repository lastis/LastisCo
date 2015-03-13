#ifdef TESTING
#include <iostream>
#endif
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    length = 0;
    head = NULL; // set head to NULL
}

// This prepends a new value at the beginning of the list
void LinkedList::add(Base* val){
    Node *n = new Node();   // create new Node
    n->val = val;           // set value
    n->next = head;         // make the node point to the next node.
                            //  If the list is empty, this is NULL, 
                            // so the end of the list --> OK
    head = n;               // last but not least, make the head 
                            // point at the new node.
    length++;
}

// returns the first element in the list and deletes the Node.
// caution, no error-checking here!
Base* LinkedList::pop(){
    Node* n = head;
    Base* val = n->val;

    head = head->next;
    length--;
    delete n;
    return val;
}

Base* LinkedList::find(int ID){
    Node* n = head;
    Base* obj = head->val;
    int objID = obj->ID;
    while (objID != ID) {
        n = n->next;
        obj = n->val;
        objID = obj->ID;
    }
    return obj;
}

bool LinkedList::isEmpty(){
    if (length == 0) return true;
    else return false;
}

LinkedList::~LinkedList(){
    while (!isEmpty()) {
        pop();
    }
}
