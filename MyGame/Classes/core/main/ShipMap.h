#ifndef __SHIP_MAP_H_INCLUDED__
#define __SHIP_MAP_H_INCLUDED__
#include "../rooms/Room.h"
#include "../map/Pathfinder.h"
#include "../items/Item.h"
#include "../items/ItemCreator.h"
#include "../enteties/Person.h"

class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();

    void updateMapAccess();
    void insertItem(int ID, Location loc);
    void insertBlocksCenter(int blockID, Location start, Location end);
    void insertBlocksFloor(int blockID, Location start, Location end);
    void insertWallHorizontal(int blockID, Location start, Location end);
    void insertWallVertical(int blockID, Location start, Location end);
    inline void simplifyLocations(Location& loc1, Location& loc2);
    Path findPath(Location start, Location end);

    void    placeRoom(Location* locations, int N, int UID);
    int     getRoomUidFromLoc(Location loc);
    bool    withinBounds(Location loc);


    bool    isVacant(int x, int y, int z);
    bool    isVacant(Location loc);

    unsigned int*** getMap();
    unsigned int*** getMapFloor();
    unsigned int*** getMapEastWalls();
    unsigned int*** getMapNorthWalls();
    unsigned int*** getMapAccess();
    unsigned int*** getMapRooms();
private:
    void initialize(int O, int N, int M);

private:
    int O;
    int N;
    int M;
    // mapAccess uses blocked movement IDs. The others
    // only use block ID to identify what is there. 
    Matrix3D containerMap;
    Matrix3D containerMapFloor;
    Matrix3D containerMapWallsEast;
    Matrix3D containerMapWallsNorth;
    Matrix3D containerMapAccess;
    Matrix3D containerMapRooms;
    unsigned int*** map;
    unsigned int*** mapFloor;
    unsigned int*** mapWallsEast;
    unsigned int*** mapWallsNorth;
    unsigned int*** mapAccess;
    unsigned int*** mapRooms;
    Pathfinder pathfinder;
};
#endif
