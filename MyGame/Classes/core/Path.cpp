#ifdef TESTING
#include <iostream>
#endif

#include "Path.h"
Path::Path(unsigned int* path, int length){
    this->path = path;
    this->length = length;
    index = 0;
}

bool Path::isComplete(){
    if (index == length) return true;
    else false;
}

bool Path::hasPath(){
    if (path != NULL) return true;
    else return false;
}

int Path::getLength(){
    return length;
}

unsigned int Path::getNextDirection(){
    using namespace directions;
    if (!hasPath()) return NO_DIRECTION;
    if (isComplete()) return NO_DIRECTION;
    index++;
    return path[index-1];
}
