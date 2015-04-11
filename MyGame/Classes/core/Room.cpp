#include "Room.h"

Room::Room(){
    // Room UID is only given in ShipMap.
    ID = 0;
    UID = 0;
    center = Location(-1,-1,-1);
}
void Room::deleteItems(){
    objects.deleteItems();
}

void Room::addItem(Item& object){
    objects.add(object);
}

Item* Room::findWithUID(int UID){
    return objects.findWithUID(UID);
}

Item* Room::removeWithUID(int UID){
    return objects.popWithUID(UID);
}

int Room::getItemCnt(){
    return objects.getLength();
}
