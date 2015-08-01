#include "ShipCrew.h"
using namespace globals;

ShipCrew::ShipCrew(){
    cntCrew = 0;
    crew = new Person*[MAX_CREW];
}

Person* ShipCrew::getCrewFromIndex(int i){
    if (i >= cntCrew) return NULL;
    return crew[i];
}

int ShipCrew::getCrewCount(){
    return cntCrew;
}

Person** ShipCrew::getCrew(){
    return crew;
}

void ShipCrew::update(ShipMaster& ship){
    for (int i = 0; i < cntCrew; i++) {
        Person* person = crew[i];
        person->update();
    }
}

Person* ShipCrew::createCrewMember(int ID, Location loc){
    if (ID == 0) return NULL;
    // Create the crew member.
    Person* crewMember = new Person();
    crewMember->loc.x = loc.x;
    crewMember->loc.y = loc.y;
    crewMember->loc.z = loc.z;
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
    delete[] crew;
}
