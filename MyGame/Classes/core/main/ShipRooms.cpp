#include "ShipRooms.h"

ShipRooms::ShipRooms(){
    cntRooms = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i] = NULL;
    }
}

int ShipRooms::getRoomCount(){
    return cntRooms;
}

bool ShipRooms::isFull(){
    // Check is against maxrooms -1 because of the relation 
    // between UID and index.
    if (cntRooms == (MAX_ROOMS-1)) return true;
    return false;
}

Room* ShipRooms::createRoom(Location location, int ID, int UID){
    if (isFull()) return NULL;
    // Case switch, create roomobject and allocate it to 
    // the rooms array. Maybe to keymap? This uses room ID.
    Room* room = new Room();
    room->center = location;
    room->UID = UID;
    rooms[cntRooms] = room;
    cntRooms++;
    return room;
}

Room* ShipRooms::getRoom(int UID){
    if (UID == 0) return NULL;
    return rooms[UID-1];
}

ShipRooms::~ShipRooms(){
    for (int i = 0; i < cntRooms; i++) {
        delete rooms[i];
    }
}
