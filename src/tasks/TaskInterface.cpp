#include "TaskInterface.h"
#include "../planner/Planner.h"

void TaskInterface::taskUndoUpdate()
{
    if(planner == nullptr)
    {
        return;
    }

    this->planner->plannerUndoUpdate(*this);
}
