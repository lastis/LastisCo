#include "ShipCrew.h"

ShipCrew::ShipCrew(){

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
    cntCrew++;
    crewMember->UID = cntCrew;
    // Add the crew member to the list.
    crew[cntCrew-1] = crewMember;
    return crewMember;
}
