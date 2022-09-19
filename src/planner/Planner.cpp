//
// Created by Kotori on 2/23/2021.
//

#include <tasks/Task.h>
#include <tasks/TaskList.h>
#include "Planner.h"
#include "../classification/classificationManager.hpp"

Planner::Planner() : classificationManager(new ClassificationManager()) {}

/**
 * Adds a task to the set.
 * @param taskInterface The task to add
 * @return true if the task was added, false if a task with the same name is already added
 */
bool Planner::addTask(TaskInterface &taskInterface) {

    taskInterface.planner = this;

    //Inserts to task set.
    if (!this->taskSet.insert(&taskInterface).second) {
        return false;
    }

    //If insert is successful
    TaskInterface *deletedInterface = &taskInterface;
    deletedInterface->setDeleted(true);
    undoTaskStack.push(deletedInterface);
    return true;
}

/**
 * Removes the task from the set
 * @param taskInterface The task to remove
 * @return true if removed, false if it was not found in the set
 */
bool Planner::removeTask(TaskInterface &taskInterface) {
    if (this->taskSet.erase(&taskInterface) != 1) {
        return false;
    }

    TaskInterface *addedInterface = &taskInterface;
    addedInterface->setDeleted(false);
    undoTaskStack.push(addedInterface);
    return true;
}

/**
 * Checks to see if a task is already in the set.
 * @param taskInterface The task to check
 * @return true if found in the set, false if not found
 */
bool Planner::hasTask(TaskInterface &taskInterface) {
    return this->taskSet.find(&taskInterface) != taskSet.end();
}

/**
 * Undoes a change that was made
 * @return true if the undo was successful, false if no more undos are left in the stack
 */
bool Planner::undo() {
    //Nothing to undo
    if (this->undoTaskStack.empty()) {
        return false;
    }

    //Pop the stack
    TaskInterface *taskInterface = this->undoTaskStack.top();
    this->undoTaskStack.pop();

    //Wrap the task from the task set
    TaskInterface *wrapped = this->wrap(taskInterface->getTitle());
    if (wrapped == nullptr) {
        wrapped = taskInterface;
        wrapped->setDeleted(true);
    } else {

        //Remove task from task set
        this->taskSet.erase(wrapped);
    }




    //If deleted from the undo stack dont do anything
    if (taskInterface->isDeleted()) {

    } else {
        this->taskSet.insert(taskInterface);
    }

    //Add the original to the redo stack.
    this->redoTaskStack.push(wrapped);

    return true;
}

///**
// * Redos the change that was done from an undo
// * @return true if the redo was successful, false if no more redos are left in the stack
// */
//bool Planner::redo() {
//    //Nothing to undo
//    if (this->redoTaskStack.empty()) {
//        return false;
//    }
//
//    //Pop the stack
//    TaskInterface *taskInterface = this->redoTaskStack.top();
//    this->redoTaskStack.pop();
//
//    bool isDeleted = taskInterface->isDeleted();
//
//    //Remove task from task set
//    this->removeTask(*taskInterface);
//
//
//    //If deleted from the undo stack dont do anything
//    if (isDeleted) {
//    } else {
//        this->addTask(*taskInterface);
//    }
//
//    return true;
//}

/**
 * Wraps the name of a task into a TaskInterface
 * @param nameOfTask The name of the task we are searching for.
 * @return TaskInterface* if the name of the task was found in the set, nullptr if not found
 */
TaskInterface *Planner::wrap(std::string nameOfTask) {
    for (TaskInterface *taskInterface : this->taskSet)
        if (taskInterface->getTitle() == nameOfTask)
            return taskInterface;
    return nullptr;
}

/**
 * Returns a collection of tasks with the same classification
 * @param classification The classification object we are searching through tasks
 * @return A set that contains all tasks with the same classification
 */
std::set<TaskInterface *> Planner::getByClassification(Classification *classification) {
    std::set<TaskInterface *> taskSet;
    for (TaskInterface *taskInterface : this->taskSet)
        if (taskInterface->getClassification() == classification)
            taskSet.insert(taskInterface);
    return taskSet;
}

void Planner::plannerUndoUpdate(TaskInterface &taskInterface) {

    TaskInterface *undoInterface;

    if (Task *task = dynamic_cast<Task *>(&taskInterface)) {
        undoInterface = new Task(*task);
    } else if (TaskList *tl = dynamic_cast<TaskList *>(&taskInterface)) {
        undoInterface = new TaskList(*tl);
    }

    undoInterface->setDeleted(false);
    undoTaskStack.push(undoInterface);
}

void Planner::remind(std::ostream &ostream) {
    for (TaskInterface *taskInterface : taskSet) {
        taskInterface->remindTask(ostream);
    }
}

/*
 *
 * Getters
 *
 */

ClassificationManager *Planner::getClassificationManager() {
    return this->classificationManager;
}
