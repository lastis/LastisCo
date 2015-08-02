#ifndef __SHIP_ROOMS_H_INCLUDED__
#define __SHIP_ROOMS_H_INCLUDED__
#include "../rooms/Room.h"
/** \brief Handles the differnt buildings in the local world.
 * \ingroup main
 * \sa Room
 */         
class ShipRooms {
public:
    ShipRooms();
    ~ShipRooms();

    /** \brief Create a room at the locations, not finished.
     *
     * Can only create a room with a single location but should obviously be 
     * changed to take an array of locations.
     */         
    Room*   createRoom(Location locations, int ID, int UID);

    /** \brief Get a room with the given UID. 
     */         
    Room*   getRoom(int UID);

    /** \brief Get number of buildings.
     */         
    int     getRoomCount();

    /** \brief See if the array is full of buildings.
     */         
    bool    isFull();

    /** \brief Maximum number of rooms. 
     */         
    static const int MAX_ROOMS = 20;

    /** \brief Index of the last building in the array + 1.
     */         
    int     cntRooms;

    /** \brief Array of buildings.
     */         
    Room*   rooms[MAX_ROOMS];
};
#endif
