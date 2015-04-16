#ifndef __SHIP_CREW_H_INCLUDED__
#define __SHIP_CREW_H_INCLUDED__
#include "../enteties/Person.h"
#include <iostream>

class ShipCrew {
public:
    static const int MAX_CREW = 100;

    ShipCrew();
    ~ShipCrew();
    int     getCrewCount();
    Person* createCrewMember(int ID, Location loc);
    void    update();

    int cntCrew;
    Person* crew[MAX_CREW];
};
#endif
