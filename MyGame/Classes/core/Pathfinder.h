#include <iostream>
#include "PriorityQueue.h"
#include "Matrix3D.h"
#include "Identifiers.h"
#include "Path.h"
#include "Location.h"
#include "PathNode.h"

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
    void freePathNodes();
    void setMap(Matrix3D& map);
    Path findPath(Location start, Location goal);
#ifdef TESTING
    void printDirMap(int zDim);
#endif
private:
    int getHValue(PathNode* node, Location goal);
    void initialize();
    void setFValue(PathNode* node, Location goal);
    void updateGValue(PathNode* node, int direction);
    void resetPathNodes();

private:
    // Variables.
    PriorityQueue nodeList[2];
    Matrix3D containNodesClosed;
    Matrix3D containNodesOpen;
    Matrix3D containDirMap;
    unsigned int*** nodesClosed; 
    unsigned int*** nodesOpen; 
    unsigned int*** blocked; 
    unsigned int*** dirMap;
    int xDim, yDim, zDim; 
    // Used for deleting propertly.
    PathNode** nodeHooks;
    int nodeNr;

};
