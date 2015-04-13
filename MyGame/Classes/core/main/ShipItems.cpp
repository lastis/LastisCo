#include "ShipItems.h"

ShipItems::ShipItems(){

}

void ShipItems::update(){
    itemsPending.update();
    itemsPlaced.update();
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

bool ShipItems::placeItem(Item& obj){
    itemsPending.popWithUID(obj.UID);
    itemsPlaced.add(obj);
}

Item* ShipItems::createItem(int ID, int UID, Location loc){
    if (ID == 0) return NULL;
    // Create the object. Item ID is set in its constructor.
    Item* obj = item_creator::createItem(ID);
    if (obj == NULL) return NULL;
    // Set the UID of the object. 
    obj->UID = UID;
    obj->loc = loc;
    // Add the object to the pending items list. 
    itemsPending.add(*obj);
    // Return the object because many times the creator wants it.
    return obj;
}


ShipItems::~ShipItems(){
    itemsPlaced.deleteItems();
    itemsPending.deleteItems();
}
