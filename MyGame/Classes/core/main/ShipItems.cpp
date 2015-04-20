#include "ShipItems.h"

ShipItems::ShipItems(){

}

void ShipItems::update(ShipMaster& ship){
    itemsPending.update(ship);
    itemsPlaced.update(ship);
}

LinkedList& ShipItems::getItems(){
    return itemsPlaced;
}

LinkedList& ShipItems::getItemsFloor(){
    return itemsFloor;
}

LinkedList& ShipItems::getItemsNorthWalls(){
    return itemsNorthWalls;
}

LinkedList& ShipItems::getItemsEastWalls(){
    return itemsEastWalls;
}

LinkedList& ShipItems::getItemsPending(){
    return itemsPending;
}

LinkedList& ShipItems::getItemsPendingFloor(){
    return itemsPendingFloor;
}

LinkedList& ShipItems::getItemsPendingNorthWalls(){
    return itemsPendingNorthWalls;
}

LinkedList& ShipItems::getItemsPendingEastWalls(){
    return itemsPendingEastWalls;
}

int     ShipItems::getItemPlacedCount(){
    return itemsPlaced.getLength();
}

int     ShipItems::getItemPendingCount(){
    return itemsPending.getLength();
}

Item* ShipItems::getItemPlacedFromUID(int UID){
    return itemsPlaced.findWithUID(UID);
}

Item* ShipItems::getItemPlacedFromID(int ID){
    return itemsPlaced.findWithID(ID);
}

Item* ShipItems::getItemPendingFromID(int ID){
    return itemsPending.findWithID(ID);
}

Item* ShipItems::getItemPendingFromUID(int UID){
    return itemsPending.findWithID(UID);
}

Item* ShipItems::getItemPlacedFromIndex(int i){
    return itemsPlaced.findWithIndex(i);
}

Item* ShipItems::getItemPendingFromIndex(int i){
    return itemsPending.findWithIndex(i);
}

bool ShipItems::placeItem(Item* obj){
    using namespace directions;
    using namespace blocks;
    if (obj == NULL) return false;
    obj->setPlaced(true);
    /* itemsPending.popWithUID(obj->UID); */
    /* itemsPlaced.add(obj); */
    switch (obj->slot) {
        case CENTER:
            itemsPending.popWithUID(obj->UID);
            itemsPlaced.add(obj);
            break;
        case FLOOR:
            itemsPendingFloor.popWithUID(obj->UID);
            itemsFloor.add(obj);
            break;
        case WALL:
            // Direction is used to find which list the 
            // wall goes into.
            if (obj->direction == NORTH) {
                itemsPendingNorthWalls.popWithUID(obj->UID);
                itemsNorthWalls.add(obj);
            }
            if (obj->direction == EAST){
                itemsPendingEastWalls.popWithUID(obj->UID);
                itemsEastWalls.add(obj);
            }
            break;
        default:
            return false;
    }
    return true;
}

Item* ShipItems::createItem(int ID, int UID, Location loc){
    // The direction of north is default.
    return createItem(ID,UID,loc,directions::NORTH);
}

Item* ShipItems::createItem(int ID,int UID,Location loc,unsigned int direction){
    using namespace directions;
    using namespace blocks;
    if (ID == 0) return NULL;
    // Create the object. Item ID is set in its constructor.
    Item* obj = item_creator::createItem(ID);
    if (obj == NULL) return NULL;
    // Set the UID of the object. 
    obj->UID = UID;
    obj->loc = loc;
    obj->direction = direction;
    // Add the object to the correct item list.
    switch (obj->slot) {
        case CENTER:
            itemsPending.add(obj);
            break;
        case FLOOR:
            itemsPendingFloor.add(obj);
            break;
        case WALL:
            // Direction is used to find which list the 
            // wall goes into.
            if (direction == NORTH) {
                itemsPendingNorthWalls.add(obj);
                break;
            }
            if (direction == EAST) {
                itemsPendingEastWalls.add(obj);
                break;
            }
        default:
            return NULL;
    }
    // Return the object because many times the creator wants it.
    return obj;
}


ShipItems::~ShipItems(){
    while (!itemsPlaced.isEmpty()){
        delete itemsPlaced.pop();
    }
    while (!itemsPending.isEmpty()){
        Item* item =  itemsPending.pop();
        if (item != NULL) delete item;
    }
}
