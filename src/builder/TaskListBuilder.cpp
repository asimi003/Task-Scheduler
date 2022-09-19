#include "TaskListBuilder.hpp"
#include "../tasks/TaskList.h"
#include "../planner/Planner.h"
#include "../classification/classificationManager.hpp" 

TaskListBuilder::TaskListBuilder(std::string title) : TaskBuilderInterface(title) {
	taskList = new TaskList(title);
} 

void TaskListBuilder::buildDescription(){
	taskList->setDescription("Write a description for your task List. You can even add a subtasks!", false);
}

void TaskListBuilder::buildClassification(){
	taskList->setClassification( (planner == nullptr ? nullptr : planner->getClassificationManager()->wrap("Unnamed")) , false);
}
   
void TaskListBuilder::buildPriority(){
	taskList->setPriority(0, false);
}
    
void TaskListBuilder::buildEndDate(){
	//we want 30 minutes as default.  so 60*30;
	time_t time = 1800;
	time_t timeNow = std::time(&time);
	taskList->setEndDate(timeNow, false);
}   

void TaskListBuilder::buildDueDate(){
	time_t timeNow = std::time(0);
	taskList->setEndDate(timeNow, false);
}

TaskInterface* TaskListBuilder::getTask() {
	return taskList;
}
