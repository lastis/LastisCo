#ifndef __PERSON_H_INCLUDED__
#define __PERSON_H_INCLUDED__

#include "Location.h"
// Forward declare Task.
class Task;

class Person {
public:
    Location location;
    Person ();
    Task* task;

};
#endif
