#ifdef TESTING
#include <iostream>
#endif
#include "Pathfinder.h"

const int Pathfinder::X_DIR[] = {1, 0, 0, -1, 0, 0};
const int Pathfinder::Y_DIR[] = {0, 1, 0, 0, -1, 0};
const int Pathfinder::Z_DIR[] = {0, 0, 1, 0, 0, -1};

Pathfinder::Pathfinder(){
    blocked = NULL;
    xDim = 1;
    yDim = 1;
    zDim = 1;
    initialize();
}

Pathfinder::Pathfinder(const Pathfinder &obj){
    copy(obj);
}

Pathfinder& Pathfinder::operator= (const Pathfinder& obj){
    copy(obj);
}

void Pathfinder::copy(const Pathfinder &obj){
    freeMemory();
    xDim = obj.xDim;
    yDim = obj.yDim;
    zDim = obj.zDim;
    blocked = obj.blocked;
    initialize();
}

Pathfinder::Pathfinder(Matrix3D& map){
    setMap(map);
    initialize();
}

Pathfinder::~Pathfinder(){
    freeMemory();
}

void Pathfinder::freeMemory(){
    for (int i = 0; i < nodeNr; i++) {
        delete nodeHooks[i];
    }
    nodeNr = 0;
    delete[] nodeHooks;
}

void Pathfinder::freeNodes(){
    for (int i = 0; i < nodeNr; i++) {
        delete nodeHooks[i];
    }
    nodeNr = 0;
}

void Pathfinder::initialize(){
    containNodesOpen = Matrix3D(zDim, yDim, xDim);
    containNodesClosed = Matrix3D(zDim, yDim, xDim);
    containDirMap =  Matrix3D(zDim, yDim, xDim);
    nodesOpen = containNodesOpen.getMatrix();
    nodesClosed = containNodesClosed.getMatrix();
    dirMap = containDirMap.getMatrix();
    nodeHooks = new Node*[zDim*yDim*xDim];
    nodeNr = 0;
}

void Pathfinder::setMap(Matrix3D& map){
    blocked = map.getMatrix();
    xDim = map.getM();
    yDim = map.getN();
    zDim = map.getO();
}

int Pathfinder::getHValue(Node* node, Location goal){
    // Manhatten distance. 
    int dx = node->x - goal.x;
    int dy = node->y - goal.y;
    int dz = node->z - goal.z;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    if (dz < 0) dz = -dz;
    return dx + dy + dz;
}

void Pathfinder::setFValue(Node* node, Location goal){
    node->fValue = node->gValue + getHValue(node, goal) * 10;
}


void Pathfinder::updateGValue(Node* node, int direction){
    // TODO: Accomidate weight. 
    node->gValue += 10;
    return;
}

void Pathfinder::resetNodes(){
    for (int i = 0; i < zDim; i++) {
        for (int j = 0; j < yDim; j++) {
            for (int k = 0; k < xDim; k++) {
                nodesOpen[i][j][k] = 0;
                nodesClosed[i][j][k] = 0;
            }
        }
    }
}


void Pathfinder::findPath(Location start, Location goal, int N, int* path){
    // This is a quickfix to fill the path from start to finish.
    Location temp = start;
    start = goal;
    goal = temp;

    Node* node1;
    Node* node2;
    int index = 0;
    int xNext, yNext, zNext;
    node1 = new Node(start);
    nodeHooks[nodeNr] = node1;
    nodeNr++;

    resetNodes();

    /* setFValue(nodeStart, goal); */
    setFValue(node1, goal);
    // Put the first open node on the list.
    nodeList[index].push(node1);
    // A* search
    while(!nodeList[index].empty()){
        // Find the node with the lower f-value.
        /* if (node1 == NULL) node1 = new Node(); */
        node1 = new Node();
        nodeHooks[nodeNr] = node1;
        nodeNr++;
        node1->fValue = nodeList[index].top()->fValue;
        node1->gValue = nodeList[index].top()->gValue;
        node1->x = nodeList[index].top()->x;
        node1->y = nodeList[index].top()->y;
        node1->z = nodeList[index].top()->z;
        // Remove the node from the list and add it to the closed. 
        nodeList[index].pop();
        nodesOpen[node1->x][node1->y][node1->z] = 0;
        nodesClosed[node1->x][node1->y][node1->z] = 1;
        // Stop searching when the goal is reached.
        if (node1->x == goal.x && node1->y == goal.y && node1->z == goal.z){
            // Generate map from finish to start.
            int X = node1->x;
            int Y = node1->y;
            int Z = node1->z;
            int cnt = 0;
            while(!(X == start.x && Y == start.y && Z == start.z)){
                // We only have a given array, fill it as much as possible.
                if (cnt == N) break;
                int dir = dirMap[X][Y][Z];
                path[cnt] = dir;
                cnt++;
                X += X_DIR[dir];
                Y += Y_DIR[dir];
                Z += Z_DIR[dir];
            }
            // Put end of line symbol (-1).
            if (cnt == N)  cnt = cnt - 1;
            path[cnt] = -1;
            // Empty the list
            while (!nodeList[index].empty()) nodeList[index].pop();
            // Return path
            freeNodes();
            return;
        }
        // Generate moves in all possible directions.
        for (int i = 0; i < DIRECTIONS; i++) {
            xNext = node1->x + X_DIR[i];
            yNext = node1->y + Y_DIR[i];
            zNext = node1->z + Z_DIR[i];
            // If not obstacle nor in closed list.
            if (xNext < 0 || xNext >= xDim) continue;
            if (yNext < 0 || yNext >= yDim) continue;
            if (zNext < 0 || zNext >= zDim) continue;
            if (blocked[xNext][yNext][zNext] == 1) continue;
            if (nodesClosed[xNext][yNext][zNext] == 1) continue;
            // Generate a child node.
            node2 = new Node(xNext,yNext,zNext);
            nodeHooks[nodeNr] = node2;
            nodeNr++;
            node2->gValue = node1->gValue;
            updateGValue(node2, i);
            setFValue(node2, goal);
            // Add it to the open list if it is not there. 
            if (nodesOpen[xNext][yNext][zNext] == 0) {
                nodesOpen[xNext][yNext][zNext] = node2->fValue;
                nodeList[index].push(node2);
                // Mark it's parent node direction
                dirMap[xNext][yNext][zNext] = (i + DIRECTIONS/2)%DIRECTIONS;
            }
            // Already in the open list.
            else if (nodesOpen[xNext][yNext][zNext] > node2->fValue) {
                // Update f-value.
                nodesOpen[xNext][yNext][zNext] = node2->fValue;
                // Update the parent directinon info, mark it's parent.
                dirMap[xNext][yNext][zNext] = (i + DIRECTIONS/2)%DIRECTIONS;

                // Replace the node by emptying one nodeList to the other
                // except the node to be replaced will be ignored and 
                // the new node will be pushed instead. 
                while (!(nodeList[index].top()->x == xNext &&
                            nodeList[index].top()->y == yNext &&
                            nodeList[index].top()->z == zNext)) {
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
            /* else delete node2; */
        }
        // Else delete node 1. 
        /* delete node1; */
    }
    // Return empty path. 
    path[0] = -1;
    freeNodes();
}

