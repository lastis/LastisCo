#ifndef __PATH_NODE_H_INCLUDED__
#define __PATH_NODE_H_INCLUDED__

#include "Location.h"
/** A path node used by the pathfinding algorithm.
 * \ingroup map
 */         
struct PathNode{
    int x;
    int y;
    int z;
    int fValue;
    int gValue;

    PathNode(){
        x = 0;
        y = 0;
        z = 0;
        fValue = 0;
        gValue = 0;
    }

    PathNode(Location loc){
        x = loc.x;
        y = loc.y;
        z = loc.z;
        fValue = 0;
        gValue = 0;
    }
    

    PathNode(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
        fValue = 0;
        gValue = 0;
    }

    PathNode(const PathNode &obj){
        copy(obj);
    }


    PathNode& operator= (const PathNode& obj){
        copy(obj);
    }

    void copy(const PathNode &obj){
        x = obj.x;
        y = obj.y;
        z = obj.z;
        fValue = obj.fValue;
        gValue = obj.gValue;
    }
};
#endif
