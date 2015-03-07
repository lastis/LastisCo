#ifdef TESTING
#include <iostream>
#endif
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(){
    front = NULL;
    N = 0;
}

void PriorityQueue::push(Node& node){
    N++;
    if (front == NULL || node.fValue < front->fValue){
        node.link = front;
        front = &node;
    }
    else{
        Node* tmp = front;
        while (tmp->link != NULL && tmp->link->fValue <= node.fValue)
        tmp = tmp->link;
        node.link = tmp->link;
        tmp->link = &node;
    }
}

void PriorityQueue::pop(){
    N--;
    Node *tmp;
    if(front == NULL)
        return; // Queue underflow.
    else{
        tmp = front;
        front = front->link;
    }
}

Node* PriorityQueue::top(){
    if (front == NULL)
        return NULL;
    else{   
        return front;
    }
}

bool PriorityQueue::empty(){
    if(N == 0)return true;
    else return false;
}
int PriorityQueue::size(){
    return N;
}


