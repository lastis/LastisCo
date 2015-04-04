#ifdef TESTING
#include <iostream>
#endif

#include "PriorityQueue.h"
#include "Matrix3D.h"
#include "Identifiers.h"
#include "Path.h"

class Pathfinder {

    static const int X_DIR[directions::DIRECTIONS];
    static const int Y_DIR[directions::DIRECTIONS];
    static const int Z_DIR[directions::DIRECTIONS];
    

public:
    // Functions.
    Pathfinder();
    Pathfinder(Matrix3D& map);
    ~Pathfinder();
    Pathfinder(const Pathfinder &obj);
    Pathfinder& operator= (const Pathfinder& obj);
    void copy(const Pathfinder &obj);
    void freeMemory();
    void freeNodes();
    void setMap(Matrix3D& map);
    Path findPath(Location start, Location goal);
#ifdef TESTING
    void printDirMap(int zDim);
#endif
private:
    int getHValue(Node* node, Location goal);
    void initialize();
    void setFValue(Node* node, Location goal);
    void updateGValue(Node* node, int direction);
    void resetNodes();

private:
    // Variables.
    PriorityQueue nodeList[2];
    Matrix3D containNodesClosed;
    Matrix3D containNodesOpen;
    Matrix3D containDirMap;
    unsigned int*** nodesClosed; // TODO Initiate this array.
    unsigned int*** nodesOpen; // TODO Initiate this array.
    unsigned int*** blocked; // TODO Might not need this. 
    unsigned int*** dirMap;
    int xDim, yDim, zDim; // TODO get these from the map. Rename maybe. 
    // Used for deleting propertly.
    Node** nodeHooks;
    int nodeNr;
};
