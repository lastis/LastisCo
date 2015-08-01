#ifndef __PRIORITY_QUEUE_H_INCLUDED__
#define __PRIORITY_QUEUE_H_INCLUDED__

#include <iostream>
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

/** \brief Holds PathNode objects.
 * \ingroup map
 *
 * Used by the pathfinding algorithm to sort path nodes by fValue.
 */         
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
