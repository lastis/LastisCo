#ifndef __PRIORITY_QUEUE_H_INCLUDED__
#define __PRIORITY_QUEUE_H_INCLUDED__

#ifdef TESTING
#include <iostream>
#endif
#include "PathNode.h"

struct PriorityNode
{
    PriorityNode* link;
    PathNode* item;

    PriorityNode(){
        link = NULL;
        item = NULL;
    }
};

class PriorityQueue{
public:
    PriorityQueue();
    ~PriorityQueue();
    void push(PathNode* node);
    PathNode* top();
    bool has(PathNode* node);
    void pop();
    void clear();
    bool empty();
    int size();
private:
    int N;
    PriorityNode* front;
};


#endif
