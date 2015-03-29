#include "TaskMove.h"
#include "../Person.h"

void TaskMove::doTask(Person& person){
    bool finished = walkOneStep(person);
    if (finished) person.task = NULL;
}
