#ifndef __SHIP_CREW_H_INCLUDED__
#define __SHIP_CREW_H_INCLUDED__
#include "../enteties/Person.h"
#include "../identifiers.h"
#include <iostream>

class ShipMaster;
class ShipCrew {
public:
    ShipCrew();
    ~ShipCrew();
    int     getCrewCount();
    Person* getCrewFromIndex(int i);
    Person* createCrewMember(int ID, Location loc);
    Person** getCrew();
    void    update(ShipMaster& ship);

    int cntCrew;
    Person** crew;
};
#endif
