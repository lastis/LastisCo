#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    length = 0;
    head = NULL; 
    iteratorNode = head;
}

Item* LinkedList::next(){
    if (iteratorNode == NULL) return NULL;
    Node* n = iteratorNode;
    iteratorNode = iteratorNode->next;
    return n->val;
}

void LinkedList::resetIterator(){
    iteratorNode = head;
}

void LinkedList::update(ShipMaster& ship){
    Node* n = head;
    while (n != NULL) {
        n->val->update(ship);
        n = n->next;
    }
}

// This prepends a new value at the beginning of the list
void LinkedList::add(Item* val){
    if (val == NULL) return;
    Node *n = new Node();   // create new Node
    n->val = val;           // set value
    n->next = head;         // make the node point to the next node.
                            //  If the list is empty, this is NULL, 
                            // so the end of the list --> OK
    head = n;               // last but not least, make the head 
                            // point at the new node.
    iteratorNode = head;
    length++;
}

// returns the first element in the list and deletes the Node.
// caution, no error-checking here!
Item* LinkedList::pop(){
    if (length == 0) return NULL;
    Node* n = head;
    Item* val = n->val;

    head = head->next;
    length--;
    delete n;
    return val;
}

Item* LinkedList::findWithIndex(int i){
    Node* n = head;
    int curIndex = 0;
    while (curIndex != i) {
        if (n == NULL) return NULL;
        n = n->next;
        curIndex++;
    }
    return n->val;
}

Item* LinkedList::findWithID(int ID){
    if (length == 0) return NULL;
    Node* n = head;
    Item* obj = head->val;
    int objID = obj->ID;
    while (objID != ID) {
        n = n->next;
        if (n == NULL) return NULL;
        obj = n->val;
        objID = obj->ID;
    }
    return obj;
}

Item* LinkedList::findWithUID(int UID){
    if (length == 0) return NULL;
    Node* n = head;
    Item* obj = head->val;
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

Item* LinkedList::popWithUID(int UID){
    if (length == 0) return NULL;
    Node* prev = NULL;
    Node* cur = head;
    Item* curObj = head->val;
    int  curUID = curObj->UID;
    // Check if first node is the right one.
    if (curUID == UID){
        return pop();
    }
    // Else we look for it. 
    while (curUID != UID) {
        prev = cur;
        cur = cur->next;
        if (cur == NULL) return NULL;
        curObj = cur->val;
        curUID = curObj->UID;
    }
    // Found it
    length--;
    prev->next = cur->next;
    delete cur;
    return curObj;
}

Item* LinkedList::popWithID(int ID){
    if (length == 0) return NULL;
    if (ID == 0) return NULL;
    Node* prev = NULL;
    Node* cur = head;
    Item* curObj = head->val;
    int  curID = curObj->ID;
    // Check if first node is the right one.
    if (curID == ID){
        return pop();
    }
    // Else we look for it. 
    while (curID != ID) {
        prev = cur;
        cur = cur->next;
        // End of list.
        if (cur == NULL) return NULL;
        curObj = cur->val;
        curID = curObj->ID;
    }
    // Found it
    length--;
    prev->next = cur->next;
    delete cur;
    return curObj;
}

bool LinkedList::isEmpty(){
    if (length == 0) return true;
    else return false;
}

/* void LinkedList::deleteItems(){ */
/*     while (!isEmpty()){ */
/*         delete pop(); */
/*     } */
/* } */

LinkedList::~LinkedList(){
    while (!isEmpty()) {
        pop();
    }
}
