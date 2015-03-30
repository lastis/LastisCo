#include "Room.h"

Room::Room(){
    // Room UID is only given in ShipMap.
    ID = 0;
    UID = 0;
    center = Location(-1,-1,-1);
}
void Room::deleteObjects(){
    objects.deleteObjects();
}

void Room::addObject(Object& object){
    objects.add(object);
}

Object* Room::findWithUID(int UID){
    return objects.findWithUID(UID);
}

Object* Room::removeWithUID(int UID){
    return objects.popWithUID(UID);
}

int Room::getObjectCnt(){
    return objects.getLength();
}
