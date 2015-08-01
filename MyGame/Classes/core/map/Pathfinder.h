#ifndef __PATHFINDER_H_INCLUDED__
#define __PATHFINDER_H_INCLUDED__

#include <iostream>
#include "../identifiers.h"
#include "PriorityQueue.h"
#include "Matrix3D.h"
#include "Location.h"
#include "PathNode.h"
#include "Path.h"

/** \brief Pathfinding algorithm object.
 * \ingroup map
 * \sa findPath
 */         
class Pathfinder {

private:
    static const int X_DIR[directions::DIRECTIONS]; 
    static const int Y_DIR[directions::DIRECTIONS];
    static const int Z_DIR[directions::DIRECTIONS];
    

public:
    // Functions.
    /** \brief Empty constructor.
     */         
    Pathfinder();

    /** \brief Initialize the pathfinde with a local world map.
     * \parma map Local world.
     */         
    Pathfinder(Matrix3D& map);

    ~Pathfinder();

    Pathfinder(const Pathfinder &obj);

    Pathfinder& operator= (const Pathfinder& obj);

    /** \brief Copy function. 
     * \param obj Pathfinder to copy. 
     */         
    void copy(const Pathfinder &obj);

    /** \brief Frees internal memory.
     */         
    void freeMemory();

    /** \brief Frees memory of nodeHooks
     */         
    void freePathNodes();

    /** \brief Assigned a different local world to the pathfinding object.
     * \param map New local world. 
     */         
    void setMap(Matrix3D& map);

    /** \brief Finds a path from start to goal.
     *
     * \param start Location of start.
     * \param goal Location of goal.
     * \return A path object containg the path.
     */         
    Path findPath(Location start, Location goal);
#ifdef TESTING
    /** \brief Debug: Prints the whole direction matrix.
     *
     * The A* algorithm generates paths while running. These trial paths
     * are stored in a matrix. Can be printed with this function.
     * \param zDim Which level z level to show. 
     */         
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
    PathNode** nodeHooks; ///< Empty list of nodes, filled during pathfinding. 
    int nodeNr;

};
#endif
