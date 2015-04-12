#include "ShipItems.h"

int     ShipItems::getItemCount(){
    return objects.getLength();
}

int     ShipItems::getItemPendingCount(){
    return objectsPending.getLength();
}

Item* ShipItems::getItemFromUID(int UID){
    return objects.findWithUID(UID);
}

Item* ShipItems::getItemPendingFromID(int ID){
    return objectsPending.findWithID(ID);
}

Item* ShipItems::getItemFromIndex(int i){
    return objects.findWithIndex(i);
}

Item* ShipItems::getItemPendingFromIndex(int i){
    return objectsPending.findWithIndex(i);
}

bool addItemPending(Item& obj){
    // When the objects become placed, they are removed from the pending
    // objects list and added to a spesific room's object list and
    // the general object list.
    objectsPending.popWithUID(obj.UID);
    if (room != NULL) {
        room->addItem(obj);
    }
    objects.add(obj);
}

ShipItems::~ShipItems(){
    objects.deleteItems();
    objectsPending.deleteItems();
}
