#ifndef FINALPROJECT_TASKLIST_H
#define FINALPROJECT_TASKLIST_H

#include "TaskInterface.h"
#include <set>

class TaskList : public TaskInterface {
private:
    friend Planner;
    std::set<TaskInterface*> taskList;
public:

    virtual ~TaskList()
    {
        for(TaskInterface* taskInterface : taskList)
        {
            delete taskInterface;
        }
    }

    TaskList &operator=(const TaskList &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;

        this->taskList = other.taskList;

    }

    TaskList &operator=(TaskList &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;

        this->taskList = other.taskList;

    }

    TaskList(std::string title);
    bool addSubtask(TaskInterface*);
    bool removeSubtask(TaskInterface*);
    bool hasSubtask(TaskInterface*);

    virtual void remindTask(std::ostream& ostream) const override;

};


#endif //FINALPROJECT_TASKLIST_H
