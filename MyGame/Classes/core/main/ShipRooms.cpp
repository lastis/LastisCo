#include "ShipRooms.h"

ShipRooms::ShipRooms(){
    cntRooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = NULL;
    }
}
