#ifndef __SHIP_WEAPONS_H_INCLUDED__
#define __SHIP_WEAPONS_H_INCLUDED__
#include "../items/LinkedList.h"

class ShipMaster;

/** \brief System that resolves firing from one ship at an other. 
 *
 * \ingroup main
 * Not going to be used for the new game.
 *
 * When a weapon (Item) is ready to fire, it will call the fire method in ShipMaster,
 * which will in turn put that item in a list of weapons that are pending to be resolved. 
 * ShipWeapons will then resolve the firing when the fireAtShip() method is called. 
 */         
class ShipWeapons {
public:
    ShipWeapons();
    void fire(Item* weapon);
    void fireAtShip(ShipMaster targetShip);


    LinkedList weapons; ///< List of weapons that will be fired by this object.
};

#endif
