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
    // Return true if the walk is finished
    using namespace directions;
    if (path == NULL) return true;
    unsigned int dir = path->getNextDirection();
    Location& loc = person.loc;
    
    switch (dir) {
        case NO_DIRECTION :
            break;
        case EAST :
            loc.x++;
            break;
        case WEST :
            loc.x--;
            break;
        case NORTH :
            loc.y++;
            break;
        case SOUTH :
            loc.y--;
            break;
        case UP :
            loc.z++;
            break;
        case DOWN :
            loc.z--;
            break;
        default:
            return true;
    }
    // Path is finished when the path is finished.
    return path->isComplete();
}

