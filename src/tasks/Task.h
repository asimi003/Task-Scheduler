#ifndef FINALPROJECT_TASK_H
#define FINALPROJECT_TASK_H

#include "TaskInterface.h"

class Task : public TaskInterface {
private:
    friend Planner;
public:
    Task(std::string title);

    Task &operator=(const Task &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }

    Task &operator=(Task &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }


    virtual void remindTask(std::ostream& ostream) const override;
};

#endif
