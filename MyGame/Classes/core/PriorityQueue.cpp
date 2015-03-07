#ifdef TESTING
#include <iostream>
#endif
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(){
    front = NULL;
    N = 0;
}

bool PriorityQueue::has(Node* node){
    PriorityNode* tmp = front;
    while(tmp != NULL){
        if(node == tmp->item) return true;
        tmp = tmp->link;
    }
    return false;
}

void PriorityQueue::push(Node* node){
    /* if (has(node)) std::cout << "HAS NODE, BAD STUFF" << std::endl; */
    PriorityNode* container = new PriorityNode();
    container->item = node;
    if (front == NULL || node->fValue < front->item->fValue){
        container->link = front;
        front = container;
    }
    else{
        PriorityNode* tmp = front;
        while (tmp->link != NULL && tmp->link->item->fValue <= node->fValue)
        tmp = tmp->link;
        // Now tmp.link.fValue > node.fValue, put node in here. 
        container->link = tmp->link;
        tmp->link = container;
    }
    N++;
}

void PriorityQueue::pop(){
    PriorityNode *tmp;
    if(front == NULL)
        return; // Queue underflow.
    else{
        tmp = front;
        front = front->link;
        N--;
    }
}

Node* PriorityQueue::top(){
    if (front == NULL)
        return NULL;
    else{   
        return front->item;
    }
}

bool PriorityQueue::empty(){
    if(N == 0)return true;
    else return false;
}
int PriorityQueue::size(){
    return N;
}


