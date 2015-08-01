#ifndef __UTIL_H_INCLUDED__
#define __UTIL_H_INCLUDED__
#include "map/Location.h"
/** \brief Utility functions. 
 *
 * Contains mostly mics. static functions, but also functions that does not fit
 * well into anywhere else.
 */         
namespace util{

    /** \brief Calculate the manhatten distance
     *
     * Used in the pathfinder when calculating how close a node is to the
     * goal.
     * \param loc1 Location 1. 
     * \param loc2 Location 2.
     * \return Distance in Manhatten.
     */         
    int static distanceManhatten(Location loc1, Location loc2){
        // Manhatten distance. 
        int dx = loc1.x - loc2.x;
        int dy = loc1.y - loc2.y;
        int dz = loc1.z - loc2.z;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        if (dz < 0) dz = -dz;
        return dx + dy + dz;
    }
}
#endif
