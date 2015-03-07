#ifdef TESTING
#include <iostream>
#endif
#include "Matrix3D.h"
#include "PriorityQueue.h"

class Pathfinder {
    // Functions.
public:
    Pathfinder ();
    void findPath(Location start, Location goal);
private:
    int getHValue(Node& node, Location goal);
    void setFValue(Node& node, Location goal);
    void updateGValue(Node& node, int direction);

    // Variables.
private:
    static const int DIRECTIONS = 6;
    static const int X_DIR[DIRECTIONS];
    static const int Y_DIR[DIRECTIONS];
    static const int Z_DIR[DIRECTIONS];
    Node node1;
    Node node2;
    int xNext, yNext, zNext;
    PriorityQueue nodeList[2];
    int*** nodesClosed; // TODO Initiate this array.
    int*** nodesOpen; // TODO Initiate this array.
    int*** blocked; // TODO Might not need this. 
    int*** dirMap;
    int xDim, yDim, zDim; // TODO get these from the map. Rename maybe. 
};
