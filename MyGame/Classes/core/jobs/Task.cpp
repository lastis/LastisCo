#include "Task.h"
#include "../Person.h"
#include "../Path.h"
#include <iostream>

void Task::setPath(Path& path){
    this->path = path;
}

void Task::setFinished(bool val){
    finished = val;
}

bool Task::isFinished(){
    return finished;
}

bool Task::hasPath(){
    return path.hasPath();
}

bool Task::walkOneStep(Person& person){
    // If the path is non-existant the path is most likely blocked,
    // so we need to finish the task.
    if (path.hasPath() == false) setFinished(true);
    // Return true if the walk is finished, also return true
    // if a path is not valid. 
    using namespace directions;
    unsigned int dir = path.getNextDirection();
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
    }
    return path.isComplete();
}
