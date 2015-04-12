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
