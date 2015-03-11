#ifndef __ROOM__HINCLUDED__
#define __ROOM__HINCLUDED__
#include "Location.h"
class Room {
public:
    Room ();
    Location findObject(int objectID);

    Location center;
    int ID;

};
#endif
