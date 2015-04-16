#include "ShipCrew.h"

ShipCrew::ShipCrew(){
    cntCrew = 0;
    for (int i = 0; i < MAX_CREW; i++) {
        crew[i] = NULL;
    }
}

Person* ShipCrew::getCrewFromIndex(int i){
    if (i >= cntCrew) return NULL;
    return crew[i];
}

int ShipCrew::getCrewCount(){
    return cntCrew;
}

void ShipCrew::update(){
    for (int i = 0; i < cntCrew; i++) {
        Person* person = crew[i];
        person->update();
    }
}

Person* ShipCrew::createCrewMember(int ID, Location loc){
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
