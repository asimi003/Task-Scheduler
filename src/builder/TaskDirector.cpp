#include <iostream>

#include "TaskDirector.hpp"
#include "TaskBuilderInterface.hpp"

TaskDirector::TaskDirector(Planner* planner, TaskBuilderInterface *taskBuilderInterface) {
	this->taskBuilder = taskBuilderInterface;
	this->planner = planner;
}

void TaskDirector::constructTask() {
	this->taskBuilder->planner = planner;
	this->taskBuilder->buildDescription();
	this->taskBuilder->buildClassification();
	this->taskBuilder->buildDueDate();
	this->taskBuilder->buildEndDate();
	this->taskBuilder->buildPriority();
}

TaskInterface* TaskDirector::getTask() {
        return this->taskBuilder->getTask();
}

