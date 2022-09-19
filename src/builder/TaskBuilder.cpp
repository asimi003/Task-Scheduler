#include "TaskBuilder.hpp"
#include "../tasks/Task.h"
#include "../planner/Planner.h"
#include "../classification/classificationManager.hpp"


TaskBuilder::TaskBuilder(std::string title) : TaskBuilderInterface(title) {task = new Task(title);}

void TaskBuilder::buildDescription()
{
    task->setDescription("Write a description for your task.", false);
}

void TaskBuilder::buildClassification()
{

    task->setClassification( (planner == nullptr ? nullptr : planner->getClassificationManager()->wrap("Unnamed")) , false);
}

void TaskBuilder::buildPriority()
{
    task->setPriority(0, false);
}

void TaskBuilder::buildEndDate()
{
    // We want 30 minutes as a default. 60*30;
    time_t time = 1800;
    time_t timeNow = std::time(&time) ;
    task->setEndDate(timeNow, false);
}

void TaskBuilder::buildDueDate() {
    time_t timeNow = std::time(0) ;
    task->setEndDate(timeNow, false);
}

TaskInterface* TaskBuilder::getTask()
{
    return task;
}
