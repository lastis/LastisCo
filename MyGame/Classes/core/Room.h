#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
class Room {
public:
    Room();
    Location findObjectLocation(int objectID);

    Location center;
    unsigned int label;
    /* char name[10]; */

};
#endif
