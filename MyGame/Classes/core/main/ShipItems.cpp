#include "ShipItems.h"

ShipItems::ShipItems(){
    ShipItems(1,1,1);
}

ShipItems::ShipItems(int O, int N, int M) : itemsMapContainer(ItemMatrix(O,N,M)){
    itemsMap = itemsMapContainer.getMatrix();
}

void ShipItems::update(ShipMaster& ship){
    itemsPlaced.update(ship);
}

LinkedList& ShipItems::getTextureList(){
    return textureList;
}

LinkedList& ShipItems::getItems(){
    return itemsPlaced;
}

LinkedList& ShipItems::getItemsPending(){
    return itemsPending;
}

int     ShipItems::getItemPlacedCount(){
    return itemsPlaced.getLength();
}

int     ShipItems::getItemPendingCount(){
    return itemsPending.getLength();
}

Item*   ShipItems::getItemPlacedFromID(int ID){
    return itemsPlaced.findWithID(ID);
}

Item*   ShipItems::getItemPlacedFromUID(int UID){
    return itemsPlaced.findWithUID(UID);
}

Item*   ShipItems::getItemPendingFromID(int ID){
    return itemsPending.findWithID(ID);
}

Item*   ShipItems::getItemPendingFromUID(int UID){
    return itemsPending.findWithUID(UID);
}

bool ShipItems::placeItem(Item* obj){
    using namespace directions;
    using namespace blocks;
    if (obj == NULL) return false;
    obj->setPlaced(true);
    itemsPending.popWithUID(obj->UID);
    itemsPlaced.add(obj);
    Location& loc = obj->loc;
    // The status of the item changed, so we should draw it again.
    textureList.add(obj);
    /* itemsMap[loc.z][loc.y][loc.x].add(obj); */
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
    obj->setDirection(direction);
    // Add the object to the correct item list.
    itemsPending.add(obj);
    // If everything was ok, add the object to the texture list
    // so it's texture will be drawn initially. (Because non-placed
    // objects look the same as placed objects, we remove this for now.)
    /* textureList.add(obj); */
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
