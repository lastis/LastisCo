#include <iostream>
#include "Path.h"
Path::Path(){
    this->path = NULL;
    this->length = 0;
    index = 0;
}

Path::Path(unsigned int* path, int length){
    this->path = path;
    this->length = length;
    index = 0;
}

bool Path::isComplete(){
    if (index == length) return true;
    else return false;
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

Path::Path(const Path& obj){
    copy(obj);
}

Path& Path::operator= (const Path& obj){
    copy(obj);
}

void Path::copy(const Path& obj){
    if (obj.path == NULL) {
        length = 0;
        path = NULL;
        index = 0;
    }
    length = obj.length;
    index = obj.index;
    path = new unsigned int[length];
    for (int i = 0; i < length; i++) {
        path[i] = obj.path[i];
    }
    
}

Path::~Path(){
    if (path != NULL) delete[] path;
}
