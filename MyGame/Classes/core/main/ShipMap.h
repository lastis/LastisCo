#ifndef __SHIP_MAP_H_INCLUDED__
#define __SHIP_MAP_H_INCLUDED__
#include "../rooms/Room.h"
#include "../map/Pathfinder.h"
#include "../items/Item.h"
#include "../items/ItemCreator.h"
#include "../enteties/Person.h"
#include "../identifiers.h"

class ShipMaster;
/** \brief Contains the local world.
 *
 * \ingroup main
 * The local world consists of 4 OxNxM matrices. 
 * -# Walls facing east matrix.
 * -# Walls facing north matrix.
 * -# Floor matrix.
 * -# Main block matrix. 
 *
 * This makes each box in the local world have 4 slots for walls,floor and a
 * main block that can be placed in the world. 
 *
 * Buildnings and pathfinding are also handled through this class. 
 */
class ShipMap {
public:
    ShipMap();
    ShipMap(int O, int N, int M);
    ~ShipMap();

    /** \brief See ShipMaster#updateMapAccess
     *
     * Only use when removing an item that blocks movement. Will rebuild the 
     * whole MapAccess.
     */         
    void updateMapAccess(ShipMaster& ship);

    /** \brief Makes all coordinates of loc1 less than loc2.
     * \param loc1 Location 1.
     * \param loc2 Location 2.
     */         
    inline void simplifyLocations(Location& loc1, Location& loc2);

    /** \brief Checks if a location is within the local world.
     */         
    bool    withinBounds(Location loc);

    /** \brief See ShipMaster#placeTexture
     */         
    void    placeTexture(unsigned int ID, Location loc);

    /** \brief Get a room UID from a location.
     * \param loc Location
     * \return UID
     */         
    int     getRoomUidFromLoc(Location loc);

    /** \brief Place the UID at the location.
     *
     * \param UID UID of an item. 
     */         
    void    placeItem(int UID, Location loc);

    /** \brief Places the UID at the given locations.
     *
     * \param locations Array of locations that make the buildning.
     * \param N Length of array.
     * \param UID UID to place in the room matrix.
     */         
    void    placeRoom(Location* locations, int N, int UID);

    /** \brief \see ShipMaster#isVacant
     */         
    bool    isVacant(int x, int y, int z);
    /** \brief \see ShipMaster#isVacant
     */         
    bool    isVacant(Location loc);

    /** \brief Find a path from start to end.
     * Uses the Pathfinder class.
     */         
    Path    findPath(Location start, Location end);

    unsigned int*** getMapAccess();
    unsigned int*** getMap();
    unsigned int*** getMapFloor();
    unsigned int*** getMapEastWalls();
    unsigned int*** getMapNorthWalls();
    unsigned int*** getMapRooms();
    unsigned int*** getMapTextures();
    unsigned int*** getMapTexturesFloor();
    unsigned int*** getMapTexturesEastWalls();
    unsigned int*** getMapTexturesNorthWalls();
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
    Matrix3D containerMapTextures;
    Matrix3D containerMapTexturesFloor;
    Matrix3D containerMapTexturesEastWalls;
    Matrix3D containerMapTexturesNorthWalls;
    unsigned int*** map;
    unsigned int*** mapFloor;
    unsigned int*** mapWallsEast;
    unsigned int*** mapWallsNorth;
    unsigned int*** mapAccess;
    unsigned int*** mapRooms;
    unsigned int*** mapTextures;
    unsigned int*** mapTexturesFloor;
    unsigned int*** mapTexturesEastWalls;
    unsigned int*** mapTexturesNorthWalls;
    Pathfinder pathfinder;
};
#endif
