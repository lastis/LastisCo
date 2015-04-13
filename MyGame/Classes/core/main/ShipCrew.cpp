#include "ShipCrew.h"

ShipCrew::ShipCrew(){
    cntCrew = 0;
    for (int i = 0; i < MAX_CREW; i++) {
        crew[i] = NULL;
    }
}

int ShipCrew::getCountCrew(){
    return cntCrew;
}

Person* ShipCrew::addCrewMember(int ID, Location loc){
    if (ID == 0) return NULL;
    int x = loc.x;
    int y = loc.y;
    int z = loc.z;
    // Create the crew member.
    Person* crewMember = new Person();
    // Avoid UID of 0.
    crewMember->UID = cntCrew+1;
    // Add the crew member to the list.
    crew[cntCrew] = crewMember;
    cntCrew++;
    return crewMember;
}

ShipCrew::~ShipCrew(){
    for (int i = 0; i < cntCrew; i++) {
        delete crew[i];
    }
}
