#include "TaskMove.h"
#include "../Person.h"

void TaskMove::doTask(Person& person){
    finished = walkOneStep(person);
}
