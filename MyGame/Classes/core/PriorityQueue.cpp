#ifdef TESTING
#include <iostream>
#endif
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(){
    front = NULL;
}

/* void PriorityQueue::push(int item, int priority){ */
void PriorityQueue::push(Node& node){
    /* Node* tmp, *q; */
    /* tmp = new Node; */
    /* tmp->info = item; */
    /* tmp->priority = priority; */
    /* if (front == NULL || priority < front->priority){ */
    /*     tmp->link = front; */
    /*     front = tmp; */
    /* } */
    /* else{ */
    /*     q = front; */
    /*     while (q->link != NULL && q->link->priority <= priority) */
    /*     q=q->link; */
    /*     tmp->link = q->link; */
    /*     q->link = tmp; */
    /* } */
}

void PriorityQueue::pop(){
    /* Node *tmp; */
    /* if(front == NULL); */
    /*     //cout<<"Queue Underflow\n"; */ 
    /* else{ */
    /*     tmp = front; */
    /*     /1* cout<<"Deleted item is: "<<tmp->info<<endl; *1/ */
    /*     front = front->link; */
    /*     delete tmp; */
    /* } */
}

/* void PriorityQueue::top(){ */
Node& PriorityQueue::top(){
    /* Node *ptr; */
    /* ptr = front; */
    /* if (front == NULL); */
    /* /1* cout<<"Queue is empty\n"; *1/ */
    /* else{ */   
    /*     /1* cout<<"Queue is :\n"; *1/ */
    /*     /1* cout<<"Priority       Item\n"; *1/ */
    /*     while(ptr != NULL){ */
    /*         /1* cout<<ptr->priority<<"                 "<<ptr->info<<endl; *1/ */
    /*         ptr = ptr->link; */
    /*     } */
    /* } */
}
bool PriorityQueue::empty(){
    if(N == 0)return true;
    else return false;
}
int PriorityQueue::size(){
    return N;
}


