#include "Task.h"
#include "../Person.h"
#include "../Path.h"

#ifdef TESTING
#include <iostream>
#endif

Task::Task(){
    path = NULL;
}

void Task::setPath(Path* path){
    this->path = path;
}

bool Task::walkOneStep(Person& person){
    // Return false if a diretion cannot be found.
    using namespace directions;
    if (path == NULL) return false;
    unsigned int dir = path->getNextDirection();
    Location& loc = person.loc;
    
    switch (dir) {
        case NO_DIRECTION :
            return false;
        case EAST :
            loc.x++;
            return true;
        case WEST :
            loc.x--;
            return true;
        case NORTH :
            loc.y++;
            return true;
        case SOUTH :
            loc.y--;
            return true;
        case UP :
            loc.z++;
            return true;
        case DOWN :
            loc.z--;
            return true;
        default:
            return false;
    }
}

