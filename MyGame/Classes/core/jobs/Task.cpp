#include "Task.h"
#include "../Person.h"
#include "../Path.h"
#include "../Identifiers.h"

#ifdef TESTING
#include <iostream>
#endif

Task::Task(){
    path = NULL;
}

void Task::setPath(Path* path){
    this->path = path;
}

void Task::walkOneStep(Person& person){
    using namespace directions;
    if (path == NULL) return;
    unsigned int dir = path->getNextDirection();
    Location* loc = &person.loc;
    
    switch (dir) {
        case NO_DIRECTION :
            break;
        case EAST :
            loc->x++;
            break;
        case WEST :
            loc->x--;
            break;
        case NORTH :
            loc->y++;
            break;
        case SOUTH :
            loc->y--;
            break;
        case UP :
            loc->z++;
            break;
        case DOWN :
            loc->z--;
            break;
    }
}
