//
// Created by Kotori on 2/23/2021.
//

#ifndef FINALPROJECT_PLANNER_H
#define FINALPROJECT_PLANNER_H

#include <stack>
#include <set>
#include <string>

class Classification;

#include "../tasks/TaskInterface.h"
#include "../tasks/Task.h"
#include "../tasks/TaskList.h"

#include "../classification/classificationManager.hpp"
class Planner {

private:

    struct cmpStruct {
        bool operator() (const TaskInterface * lhs, const TaskInterface * rhs) const
        {

            return lhs->dueDate < rhs->dueDate;
        }
    };

    /* Holds all the tasks. Note: They are each unique*/
    std::set<TaskInterface*> taskSet;

    /* Undo/redo tasks. Note: Stacks to pop out the most recent change */
    std::stack<TaskInterface*> undoTaskStack;
    std::stack<TaskInterface*> redoTaskStack;

    ClassificationManager* classificationManager;

    friend class TaskInterface;
    friend class Task;
    friend class TaskList;

public:

    Planner();

    ~Planner()
    {

        delete classificationManager;

        for(TaskInterface* taskInterface : taskSet)
        {
            delete taskInterface;
        }

        while(!undoTaskStack.empty())
        {
            TaskInterface* taskInterface = undoTaskStack.top();
            undoTaskStack.pop();
            delete taskInterface;
        }

        while(!redoTaskStack.empty())
        {
            TaskInterface* taskInterface = redoTaskStack.top();
            redoTaskStack.pop();
            delete taskInterface;
        }


    }

    //todo Note: Remember to check if the name is already taken!
    /**
     * Adds a task to the set.
     * @param taskInterface The task to add
     * @return true if the task was added, false if a task with the same name is already added
     */
    bool addTask(TaskInterface& taskInterface);

    /**
     * Removes the task from the set
     * @param taskInterface The task to remove
     * @return true if removed, false if it was not found in the set
     */
    bool removeTask(TaskInterface&  taskInterface);

    /**
     * Checks to see if a task is already in the set.
     * @param taskInterface The task to check
     * @return true if found in the set, false if not found
     */
    bool hasTask(TaskInterface& taskInterface);

    /**
     * Undoes a change that was made
     * @return true if the undo was successful, false if no more undos are left in the stack
     */
    bool undo();

//    /**
//     * Redos the change that was done from an undo
//     * @return true if the redo was successful, false if no more redos are left in the stack
//     */
//    bool redo();

    /**
     * Wraps the name of a task into a TaskInterface
     * @param nameOfTask The name of the task we are searching for.
     * @return TaskInterface* if the name of the task was found in the set, nullptr if not found
     */
    TaskInterface* wrap(std::string nameOfTask);

    /**
     * Returns a collection of tasks with the same classification
     * @param classification The classification object we are searching through tasks
     * @return A set that contains all tasks with the same classification
     */
    std::set<TaskInterface*> getByClassification(Classification* classification);

    void plannerUndoUpdate(TaskInterface& taskInterface);

    void remind(std::ostream&);

    /*
     *
     * Getters
     *
     */

    ClassificationManager* getClassificationManager();
};


#endif //FINALPROJECT_PLANNER_H
