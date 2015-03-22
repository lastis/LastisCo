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
    Location* loc = &person.location;
    
    switch (dir) {
        case NO_DIRECTION :
            std::cout << "1" << std::endl;
            break;
        case EAST :
            std::cout << "2" << std::endl;
            break;
        case WEST :
            std::cout << "3" << std::endl;
            break;
        case NORTH :
            std::cout << "4" << std::endl;
            break;
        case SOUTH :
            std::cout << "5" << std::endl;
            break;
        case UP :
            std::cout << "6" << std::endl;
            break;
        case DOWN :
            std::cout << "7" << std::endl;
            break;
        default : 
        std::cout << "nan" << std::endl;
    }
    /* if (dir == NO_DIRECTION) break; */
    /* if (dir == EAST) ++; */
    /* if (dir == WEST) sumX--; */
    /* if (dir == NORTH) sumY++; */
    /* if (dir == SOUTH) sumY--; */
    /* if (dir == UP) sumZ++; */
    /* if (dir == DOWN) sumZ--; */
}
