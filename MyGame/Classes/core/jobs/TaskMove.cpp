#include "TaskMove.h"
#include "../enteties/Person.h"

void TaskMove::doTask(Person& person){
    finished = walkOneStep(person);
}
