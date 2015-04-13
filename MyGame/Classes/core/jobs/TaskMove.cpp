#include "TaskMove.h"
#include "../enteties/Person.h"
#include "../main/ShipMaster.h"

TaskMove::TaskMove(ShipMaster& ship, Location currentPos, Location end) 
    :   Task(ship)
{
    setPath(ship.findPath(currentPos,end));
}

void TaskMove::doTask(Person& person){
    finished = walkOneStep(person);
}
