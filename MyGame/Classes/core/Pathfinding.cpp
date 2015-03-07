#ifdef TESTING
#include <iostream>
#endif
#include "Node.h"
#include "PriorityQueue.h"

int calculateFValue(Node& node, Location goal){
    // TODO complete these.
    return 0;
}

void updateGValue(Node& node, int direction){
    // TODO complete these.
    return;
}

const int DIRECTIONS = 6;
const int X_DIR[DIRECTIONS] = {1, -1, 0, 0, 0, 0};
const int Y_DIR[DIRECTIONS] = {0, 0, 1, -1, 0, 0};
const int Z_DIR[DIRECTIONS] = {0, 0, 0, 0, 1, -1};
Node node1;
Node node2;
int xNext, yNext, zNext;
PriorityQueue nodeList[2];
int*** nodesClosed; // TODO Initiate this array.
int*** nodesOpen; // TODO Initiate this array.
int*** blocked; // TODO Might not need this. 
int xDim, yDim, zDim; // TODO get these from the map. Rename maybe. 

void findPath(Location start, Location goal){
    int index = 0;
    node1 = Node(start);

    calculateFValue(node1,goal);
    // Put the first open node on the list.
    nodeList[index].push(node1);
    // A* search
    while(!nodeList[index].empty()){
        // Find the node with the lower f-value.
        node1 = nodeList[index].top();
        // Remove the node from the list and add it to the closed. 
        nodeList[index].pop();
        nodesOpen[node1.x][node1.y][node1.z] = 0;
        nodesClosed[node1.x][node1.y][node1.z] = 1;
        // Stop searching when the goal is reached.
        if (node1.x == goal.x && node1.y == goal.y && node1.z == goal.z) {
            // Generate map from finish to start.
            // Empty the list
            while (!nodeList[index].empty()) nodeList[index].pop();
            // Return path
            return;
        }
        // Generate moves in all possible directions.
        for (int i = 0; i < DIRECTIONS; i++) {
            xNext = node1.x + X_DIR[i];
            yNext = node1.y + Y_DIR[i];
            zNext = node1.z + Z_DIR[i];
            // If not obstacle nor in closed list.
            if (!(xNext < 0 || xNext > xDim || yNext < 0 || yNext > yDim|| 
                        zNext < 0 || zNext > zDim ||
                        blocked[xNext][yNext][zNext] == 1 ||
                        nodesClosed[xNext][yNext][zNext] == 1)) {
                // Generate a child node.
                node2 = Node(xNext,yNext,zNext);
                updateGValue(node2, i);
                calculateFValue(node2, goal);
                // Add it to the open list if it is not there. 
                if (nodesOpen[xNext][yNext][zNext] == 0) {
                    nodesOpen[xNext][yNext][zNext] = node2.fValue;
                    nodeList[index].push(node2);
                    // Mark it's parent node direction
                }
                // Already in the open list.
                else if (nodesOpen[xNext][yNext][zNext] > node2.fValue) {
                    // Update f-value.
                    nodesOpen[xNext][yNext][zNext] = node2.fValue;
                    // Update the parent directinon info, mark it's parent.
                    // TODO

                    // Replace the node by emptying one nodeList to the other
                    // except the node to be replaced will be ignored and 
                    // the new node will be pushed instead. 
                    while (!(nodeList[index].top().x == xNext &&
                                nodeList[index].top().y == yNext &&
                                nodeList[index].top().z == zNext)) {
                        nodeList[1-index].push(nodeList[index].top());
                        nodeList[index].pop();
                    }

                    // Remove the wanted node.
                    nodeList[index].pop();
                    // Empty the larger size nodeList to the empty one. 
                    if (nodeList[index].size() > nodeList[1-index].size()) {
                        index = 1-index;
                    }
                    while (!nodeList[index].empty()) {
                        nodeList[1-index].push(nodeList[index].top());
                        nodeList[index].pop();
                    }
                    index = 1-index;
                    // Add the better node instead.
                    nodeList[index].push(node2);
                }
                // Else delete node 2.
            }
        }
        // Else delete node 1. 
    }
    // No path found. 
    // Return empty path. 
}

