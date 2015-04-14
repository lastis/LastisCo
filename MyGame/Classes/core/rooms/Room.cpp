#include "Room.h"

Room::Room(){
    // Room UID is only given in ShipMap.
    ID = 0;
    UID = 0;
    center = Location(-1,-1,-1);
}

void Room::addItem(Item* object){
    objects.add(object);
}

Item* Room::getItemWithUID(int UID, bool remove){
    if (remove) return objects.popWithUID(UID);
    else        return objects.findWithUID(UID);
    
}

int Room::getItemCnt(){
    return objects.getLength();
}
