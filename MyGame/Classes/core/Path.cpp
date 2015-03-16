#include "Path.h"
Path::Path(unsigned int* path, int length){
    this->path = path;
    this->length = length;
    index = 0;
}
