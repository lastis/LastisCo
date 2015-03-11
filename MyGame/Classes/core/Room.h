#ifndef __ROOM_H_INCLUDED__
#define __ROOM_H_INCLUDED__
#include "Location.h"
class Room {
public:
    Room();
    /* Location findObject(int objectID); */

    Location center;
    unsigned int ID;

};
#endif
