#include "ShipMaster.h"

ShipMaster::ShipMaster(int O, int N, int M) : O(O), N(N), M(M), 
    crew(ShipCrew()), 
    map(ShipMap(O,N,M)), 
    items(ShipItems()), 
    jobs(ShipJobs()),
    rooms(ShipRooms())
{
    blocks::properties::initArrays();
}


Path ShipMaster::getPathToRoom(int UID, Location start){
    Location goal;
    Room* room = rooms.getRoom(UID);
    if (room != NULL) goal = rooms.getRoom(UID)->center; 
    return map.findPath(start, goal);
}

Room* ShipMaster::createRoom(Location* locations, int N, int ID){
    if (rooms.isFull()) return NULL;
    if (locations == NULL) return NULL;
    // Increase the UID index and assign it to the room.
    int UID = roomUID + 1;
    // Find a way to mark the center of the room? Using the first
    // position now.
    Room* room = rooms.createRoom(locations[0],ID,UID);
    if (room == NULL) return NULL;
    roomUID++;
    return room;
}

Room* ShipMaster::getRoom(Location loc){
    int UID = map.getRoomUidFromLoc(loc);
    return rooms.getRoom(UID);
}

bool ShipMaster::placeItem(Item& obj){
    if (obj.ID == 0) return false;
    // Check if the location is occupied.
    if (map.isVacant(obj.loc)) return false;
    map.insertItem(obj.ID,obj.loc);
    obj.setPlaced(true);
    Room* room = getRoom(obj.loc);
    items.addItem(obj);
}
