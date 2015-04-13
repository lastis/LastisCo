#include "ShipMaster.h"

ShipMaster::ShipMaster(int O, int N, int M) : O(O), N(N), M(M), 
    shipCrew(ShipCrew()), 
    shipMap(ShipMap(O,N,M)), 
    shipItems(ShipItems()), 
    shipJobs(ShipJobs()),
    shipRooms(ShipRooms())
{
    blocks::properties::initArrays();
}

Item*   ShipMaster::getItemPlacedFromID(int ID){
    return shipItems.getItemPlacedFromUID(ID);
}

Item*   ShipMaster::getItemPlacedFromUID(int UID){
    return shipItems.getItemPlacedFromUID(UID);
}

Item*   ShipMaster::getItemPlacedFromIndex(int i){
    return shipItems.getItemPlacedFromIndex(i);
}

Item*   ShipMaster::getItemPendingFromID(int ID){
    return shipItems.getItemPlacedFromID(ID);
}

Item*   ShipMaster::getItemPendingFromUID(int UID){
    return shipItems.getItemPlacedFromUID(UID);
}

Item*   ShipMaster::getItemPendingFromIndex(int i){
    return shipItems.getItemPendingFromIndex(i);
}

int     ShipMaster::getItemPlacedCount(){
    return shipItems.getItemPlacedCount();
}

int     ShipMaster::getItemPendingCount(){
    return shipItems.getItemPendingCount();
}

bool    ShipMaster::isVacant(int x, int y, int z){
    return shipMap.isVacant(x,y,z);
}

bool    ShipMaster::isVacant(Location loc){
    return shipMap.isVacant(loc);
}

Path    ShipMaster::findPath(Location start, Location end){
    return shipMap.findPath(start,end);
}

Path ShipMaster::getPathToRoom(int UID, Location start){
    Location goal;
    Room* room = shipRooms.getRoom(UID);
    if (room != NULL) goal = shipRooms.getRoom(UID)->center; 
    return shipMap.findPath(start, goal);
}

Item*   ShipMaster::createItem(int ID, Location loc){
    // Try to make a new item.
    int UID = itemUID + 1;
    Item* obj = shipItems.createItem(ID,UID,loc);
    if (obj == NULL) return NULL;
    // If successfull, increase the UID counter.
    itemUID++;
    return obj;
}

Room* ShipMaster::createRoom(Location* locations, int N, int ID){
    if (shipRooms.isFull()) return NULL;
    if (locations == NULL) return NULL;
    // Increase the UID index and assign it to the room.
    int UID = roomUID + 1;
    // Find a way to mark the center of the room? Using the first
    // position now.
    Room* room = shipRooms.createRoom(locations[0],ID,UID);
    if (room == NULL) return NULL;
    roomUID++;
    return room;
}

Room* ShipMaster::getRoom(Location loc){
    int UID = shipMap.getRoomUidFromLoc(loc);
    return shipRooms.getRoom(UID);
}

bool ShipMaster::placeItem(Item& obj){
    if (obj.ID == 0) return false;
    // Check if the location is occupied.
    if (shipMap.isVacant(obj.loc)) return false;
    shipMap.placeItem(obj.ID,obj.loc);
    obj.setPlaced(true);
    Room* room = getRoom(obj.loc);
}
