#ifndef __UTIL_H_INCLUDED__
#define __UTIL_H_INCLUDED__
#include "Location.h"
namespace util{
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
