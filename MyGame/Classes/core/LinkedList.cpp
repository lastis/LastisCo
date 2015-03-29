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
void LinkedList::add(Object& val){
    Node *n = new Node();   // create new Node
    n->val = &val;           // set value
    n->next = head;         // make the node point to the next node.
                            //  If the list is empty, this is NULL, 
                            // so the end of the list --> OK
    head = n;               // last but not least, make the head 
                            // point at the new node.
    length++;
}

// returns the first element in the list and deletes the Node.
// caution, no error-checking here!
Object* LinkedList::pop(){
    if (length == 0) return NULL;
    Node* n = head;
    Object* val = n->val;

    head = head->next;
    length--;
    delete n;
    return val;
}

Object* LinkedList::findWithUID(int UID){
    Node* n = head;
    Object* obj = head->val;
    int objUID = obj->UID;
    while (objUID != UID) {
        n = n->next;
        if (n == NULL) return NULL;
        obj = n->val;
        objUID = obj->UID;
    }
    return obj;
}

int LinkedList::getLength(){
    return length;
}

bool LinkedList::removeWithUID(int UID){
    if (length == 0) return false;
    Node* prev = NULL;
    Node* cur = head;
    Base* curObj = head->val;
    int  curUID= curObj->UID;
    while (curUID != UID) {
        prev = cur;
        cur = cur->next;
        if (cur == NULL) return false;
        curObj = cur->val;
        curUID = curObj->UID;
    }
    // Found it
    prev->next = cur->next;
    delete cur;
    length--;
    return true;
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
