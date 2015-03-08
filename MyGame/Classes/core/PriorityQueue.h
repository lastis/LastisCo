#ifdef TESTING
#include <iostream>
#endif
#include "Node.h"

struct PriorityNode
{
    PriorityNode* link;
    Node* item;

    PriorityNode(){
        link = NULL;
        item = NULL;
    }
};

class PriorityQueue{
public:
    PriorityQueue();
    ~PriorityQueue();
    void push(Node* node);
    Node* top();
    bool has(Node* node);
    void pop();
    void clear();
    bool empty();
    int size();
private:
    int N;
    PriorityNode* front;
};


