#ifdef TESTING
#include <iostream>
#endif
#include "Node.h"

class PriorityQueue{
public:
    PriorityQueue();
    void push(int item, int priority);
    void top();
    void pop();
private:
    Node* front;
};

