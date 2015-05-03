#ifndef __WEAPONRY_H_INCLUDED__
#define __WEAPONRY_H_INCLUDED__
#include "Item.h"
#include "../identifiers.h"

class Person;
class ShipMaster;
/** \brief Parent class for weapon blocks that can fire on an enemy ship.
 *
 * Objects that are ment to fire on enemy ships should inherit this class
 * to be integrated correctly into the ship system. Overriding the virtual
 * methods ensures the weapon can be handled by the system.
 */         
class Weaponry : public Item{
public:
    Weaponry(int ID, int slot, int blocking) : 
        Item(ID,slot,blocking,blocks::WEAPONRY)
    {
    }

    /** 
     * \brief Get locations of where the weapon is targeting.
     * @param loc Output list of target locations.
     * @param N Output number of target locations.
     */         
    virtual void getTargets(Location* loc, int& N) = 0;

    /** \brief Get the amount of damage given the spesific target type.
     *
     * E.g. A plasma laser might do more damage to shields.
     * @param targetType Target type identifier. 
     * @see identifiers.h
     */         
    virtual void getDamage(int targetType) = 0;

    /** \brief Get the identifier of the type of weapon damage.
     *
     * This can effect how the damage is received by the target hit.
     */         
    virtual void getDamageType() = 0;

protected:
    
};

#endif
