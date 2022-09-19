#ifndef FINALPROJECT_TASKINTERFACE_H
#define FINALPROJECT_TASKINTERFACE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include "classification/classification.hpp"

class Planner;

class TaskInterface {
private:
    Planner *planner;
    friend Planner;

protected:
    std::string title;
    std::string description;
    Classification *classification;
    unsigned int priority;
    time_t endDate;
    time_t dueDate;
    bool deleted;


public:
    TaskInterface(std::string title) : title(title), description(""), classification(nullptr), priority(0), endDate(0),
                                       dueDate(0), deleted(false), planner(nullptr) {};

    virtual ~TaskInterface()
    {
    }

    TaskInterface(const TaskInterface &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }

    TaskInterface(TaskInterface &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }

    TaskInterface &operator=(const TaskInterface &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }

    TaskInterface &operator=(TaskInterface &other) {
        this->title = other.title;
        this->description = other.description;
        this->classification = other.classification;
        this->priority = other.priority;
        this->endDate = other.endDate;
        this->dueDate = other.dueDate;
        this->deleted = other.deleted;
    }

    bool operator==(TaskInterface& rhs)
    {
        std::string oldThisTitle = this->title;
        std::transform(oldThisTitle.begin(), oldThisTitle.end(), oldThisTitle.begin(), ::tolower);

        std::string rhsThisTitle = rhs.title;
        std::transform(rhsThisTitle.begin(), rhsThisTitle.end(), rhsThisTitle.begin(), ::tolower);

        return oldThisTitle == rhsThisTitle;
    }

    bool operator==(const TaskInterface& rhs)
    {
        std::string oldThisTitle = this->title;
        std::transform(oldThisTitle.begin(), oldThisTitle.end(), oldThisTitle.begin(), ::tolower);

        std::string rhsThisTitle = rhs.title;
        std::transform(rhsThisTitle.begin(), rhsThisTitle.end(), rhsThisTitle.begin(), ::tolower);

        return oldThisTitle == rhsThisTitle;
    }

    bool operator < (const TaskInterface& rhs) const
    {
        return dueDate < rhs.dueDate;
    }

    void taskUndoUpdate();

    const std::string getTitle() const { return title; }

    const std::string getDescription() const { return description; }

    void setDescription(std::string desc) {
        taskUndoUpdate();
        this->description = desc;
    }

    void setDescription(std::string desc, bool isUpdate) {
        if(isUpdate)
        taskUndoUpdate();
        this->description = desc;
    }

     Classification *const getClassification() const { return classification; }

    void setClassification(Classification *classification1) {
        taskUndoUpdate();
        this->classification = classification1;
    }

    void setClassification(Classification *classification1, bool isUpdate) {
        if(isUpdate)
            taskUndoUpdate();        this->classification = classification1;
    }

    const unsigned int getPriority() const { return priority; }

    void setPriority(unsigned int prio) {
        taskUndoUpdate();
        this->priority = prio;
    }

    void setPriority(unsigned int prio, bool isUpdate) {
        if(isUpdate)
            taskUndoUpdate();
        this->priority = prio;
    }
    const time_t getEndDate() const { return endDate; }

    void setEndDate(time_t endDate) {
        taskUndoUpdate();
        this->endDate = endDate;
    }

    void setEndDate(time_t endDate, bool isUpdate) {
        if(isUpdate)
            taskUndoUpdate();
        this->endDate = endDate;
    }

    const time_t getDueDate() const { return dueDate; }

    void setDueDate(time_t dueDate) {
        taskUndoUpdate();
        this->dueDate = dueDate;
    }

    void setDueDate(time_t dueDate, bool isUpdate) {
        if(isUpdate)
            taskUndoUpdate();
        this->dueDate = dueDate;
    }
    const bool isDeleted() const { return deleted; }

    void setDeleted(bool isDeleted) { this->deleted = isDeleted; }


    virtual void remindTask(std::ostream &ostream) const = 0;


};


#endif //FINALPROJECT_TASKINTERFACE_H
