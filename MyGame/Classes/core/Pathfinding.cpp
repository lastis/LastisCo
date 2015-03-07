#ifdef TESTING
#include <iostream>
#endif
#include "Node.h"
#include "PriorityQueue.h"

int yDim = 8; 
int xDim = 8; 
int zDim = 8; 
const int DIRECTIONS = 6;
PriorityQueue openNodes[2];

void findPath(Location start, Location goal){
    int openIndex = 0;
    Node* node1;
    Node* node2;

    node1 = new Node(start);
}
