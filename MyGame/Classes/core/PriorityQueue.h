#ifdef TESTING
#include <iostream>
#endif
#include "Node.h"

class PriorityQueue{
public:
    PriorityQueue();
    void push(Node& node);
    Node* top();
    void pop();
    bool empty();
    int size();
private:
    int N;
    Node* front;
};

