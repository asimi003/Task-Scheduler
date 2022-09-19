#include <iostream>
#include <builder/TaskBuilder.hpp>
#include <builder/TaskListBuilder.hpp>

#include "planner/Planner.h"
#include "classification/classificationManager.hpp"
#include "builder/TaskDirector.hpp"
#include "tasks/TaskList.h"
#include "tasks/Task.h"
#include <ctime>
#include <sstream>
#include <chrono>


using namespace std;

//int main() {
//
//    Planner *planner = new Planner();
//
//
//    Classification *classification = new Classification("School", "0xc0c0c0");
//    planner->getClassificationManager()->addClassification(classification);
//
//
//    TaskBuilder *taskBuilder = new TaskBuilder("Final Project");
//    TaskDirector *taskDirector = new TaskDirector(planner, taskBuilder);
//    taskDirector->constructTask();
//
//    TaskInterface *finalProjectTask = taskDirector->getTask();
//
//    TaskListBuilder *taskListBuilder = new TaskListBuilder("3 Labs");
//
//    delete taskDirector;
//    taskDirector = new TaskDirector(planner, taskListBuilder);
//
//    taskDirector->constructTask();
//
//
//    TaskInterface *labsListTask = taskDirector->getTask();
//    labsListTask->setClassification(classification);
//
//    planner->addTask(*finalProjectTask);
//
//    planner->addTask(*labsListTask);
//
//    planner->remind(std::cout);
//    planner->undo();
//    planner->remind(std::cout);
//
//    std::stringstream stringstream;
//    planner->remind(stringstream);
//
//    std::cout << stringstream.str();
//
//    delete planner;
//    delete taskBuilder;
//    delete taskDirector;
//    delete taskListBuilder;
//
//    return 0;
//}


time_t askUserForDueDateTime() {
    time_t rawtime;
    struct tm *timeinfo;
    int year, month, day, hour, min, sec;
    const char *weekday[] = {"Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

    /* prompt user for date */
    printf("\nEnter due date year or (-1) to skip:");
    std::string yearS;
    getline(std::cin, yearS);
    year = stoi(yearS);

    printf("\nEnter due date month or (-1) to skip:");
    std::string monthS;
    getline(std::cin, monthS);
    month = stoi(monthS);

    printf("\nEnter due date day or (-1) to skip:");
    std::string dayS;
    getline(std::cin, dayS);
    day = stoi(dayS);

    printf("\nEnter due date hour or (-1) to skip:");
    std::string hourS;
    getline(std::cin, hourS);
    hour = stoi(hourS);

    printf("\nEnter due date minute or (-1) to skip:");
    std::string minS;
    getline(std::cin, minS);
    min = stoi(minS);

    printf("\nEnter due date second or (-1) to skip:");
    std::string secS;
    getline(std::cin, secS);
    sec = stoi(secS);

    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = min;
    timeinfo->tm_sec = sec;

    if (year == -1 || month == -1 || day == -1 || hour == -1 || min == -1 || sec == -1) {
        return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    }

    /* call mktime: timeinfo->tm_wday will be set */
    time_t getTime = mktime(timeinfo);

    return getTime;
}

time_t askUserForEndDateTime() {

    time_t rawtime;
    struct tm *timeinfo;
    int year, month, day, hour, min, sec;
    const char *weekday[] = {"Sunday", "Monday",
                             "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

    /* prompt user for date */
    printf("\nEnter end date year or (-1) to skip:");
    std::string yearS;
    getline(std::cin, yearS);
    year = stoi(yearS);

    printf("\nEnter end date month or (-1) to skip:");
    std::string monthS;
    getline(std::cin, monthS);
    month = stoi(monthS);

    printf("\nEnter end date day or (-1) to skip:");
    std::string dayS;
    getline(std::cin, dayS);
    day = stoi(dayS);

    printf("\nEnter end date hour or (-1) to skip:");
    std::string hourS;
    getline(std::cin, hourS);
    hour = stoi(hourS);

    printf("\nEnter end date minute or (-1) to skip:");
    std::string minS;
    getline(std::cin, minS);
    min = stoi(minS);

    printf("\nEnter end date second or (-1) to skip:");
    std::string secS;
    getline(std::cin, secS);
    sec = stoi(secS);

    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = min;
    timeinfo->tm_sec = sec;

    if (year == -1 || month == -1 || day == -1 || hour == -1 || min == -1 || sec == -1) {
        time_t seconds = 1800;
        time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()) + seconds;
        return time;
    }

    /* call mktime: timeinfo->tm_wday will be set */
    time_t getTime = mktime(timeinfo);

    return getTime;
}

int main() {

    Planner *planner = new Planner();

    int ans = 0;
    bool running = true;

    do {
        cout << "\nMain Menu\n1)Create a task\n2)Remove a task\n3)View all reminders\n4)Edit a Task\n5)Undo\n6)Exit"
             << endl;
        std::string sAns;
        getline(std::cin, sAns);
        ans = stoi(sAns);

        if (ans == 1) {
            //Create a Task Menu
            cout << "Task Menu\n1)Create a regular task\n2)Create a task list\n4)Go back" << endl;
            std::string sAns;
            getline(std::cin, sAns);
            ans = stoi(sAns);

            if (ans == 1) {
                //create a Task
                std::string title;
                cout << "\nEnter a title:";

                getline(std::cin, title);

                //create task with title ans
                TaskBuilder *builder = new TaskBuilder(title);
                TaskDirector *director = new TaskDirector(planner, builder);
                director->constructTask();
                TaskInterface *taskInterface = director->getTask();

                std::string description;
                cout << "\nEnter a description or press (N) to skip:";
                getline(std::cin, description);

                if (description != "N") {
                    taskInterface->setDescription(description, false);
                }

                std::string classificationS = "";
                cout << "\nEnter a classification or press (N) to skip:";
                getline(std::cin, classificationS);

                if (classificationS != "N") {
                    Classification *classification = planner->getClassificationManager()->wrap(classificationS);
                    if (classification == nullptr) {
                        classification = new Classification(classificationS, "0xffffff");
                    }

                    planner->getClassificationManager()->addClassification(classification);

                    taskInterface->setClassification(classification, false);
                }

                int priority;
                std::string sAns;

                cout << "\nEnter a priority or press (-1) to skip:";
                getline(std::cin, sAns);
                priority = stoi(sAns);

                if (priority != -1) {
                    taskInterface->setPriority(priority,false);
                }

                taskInterface->setDueDate(askUserForDueDateTime(), false);
                taskInterface->setEndDate(askUserForEndDateTime(), false);

                planner->addTask(*taskInterface);
                cout << "\nCompleted the task!";
                delete builder;
                delete director;

            } else if (ans == 2) {


                //create a Task
                std::string title = "";
                cout << "\nEnter a title:";
                getline(std::cin, title);

                //create task with title ans
                TaskListBuilder *builder = new TaskListBuilder(title);
                TaskDirector *director = new TaskDirector(planner, builder);
                director->constructTask();
                TaskList *taskListInterface = dynamic_cast<TaskList *>(director->getTask());

                std::string description = "";
                cout << "\nEnter a description or press (N) to skip:";
                getline(std::cin, description);

                if (description != "N") {
                    taskListInterface->setDescription(description, false);
                }

                std::string classificationS = "";
                cout << "\nEnter a classification or press (N) to skip:";
                getline(std::cin, classificationS);

                if (classificationS != "N") {
                    Classification *classification = planner->getClassificationManager()->wrap(classificationS);
                    if (classification == nullptr) {
                        classification = new Classification(classificationS, "0xffffff");
                    }

                    planner->getClassificationManager()->addClassification(classification);

                    taskListInterface->setClassification(classification, false);
                }

                int priority;
                cout << "\nEnter a priority or press (-1) to skip:";
                std::string sAns;
                getline(std::cin, sAns);
                priority = stoi(sAns);

                if (priority != -1) {
                    taskListInterface->setPriority(priority, false);
                }

                taskListInterface->setDueDate(askUserForDueDateTime(), false);
                taskListInterface->setEndDate(askUserForEndDateTime(), false);


                std::string addMore = "";

                delete builder;
                delete director;
                do {

                    std::string title = "";
                    cout << "\nEnter a title:";
                    getline(std::cin, title);

                    //create task with title ans
                    TaskBuilder *builder = new TaskBuilder(title);
                    TaskDirector *director = new TaskDirector(planner, builder);
                    director->constructTask();
                    TaskInterface *taskInterface = director->getTask();

                    std::string description = "";
                    cout << "\nEnter a description or press (N) to skip:";
                    getline(std::cin, description);

                    if (description != "N") {
                        taskInterface->setDescription(description,false);
                    }

                    std::string classificationS = "";
                    cout << "\nEnter a classification or press (N) to skip:";
                    getline(std::cin, classificationS);

                    if (classificationS != "N") {
                        Classification *classification = planner->getClassificationManager()->wrap(classificationS);
                        if (classification == nullptr) {
                            classification = new Classification(classificationS, "0xffffff");
                        }

                        planner->getClassificationManager()->addClassification(classification);

                        taskInterface->setClassification(classification, false);
                    }

                    int priority;
                    cout << "\nEnter a priority or press (-1) to skip:";
                    std::string sAns;
                    getline(std::cin, sAns);
                    priority = stoi(sAns);

                    if (priority != -1) {
                        taskInterface->setPriority(priority, false);
                    }

                    taskInterface->setDueDate(askUserForDueDateTime(), false);
                    taskInterface->setEndDate(askUserForEndDateTime(), false);


                    cout << "\nAdd more to the task list (Y/N)?:" << endl;
                    getline(std::cin, addMore);
                    delete builder;
                    delete director;

                } while (addMore == "Y");

                planner->addTask(*taskListInterface);

                cout << "\nCompleted the task list!";
            } else {
                //go back to original Menu
            }
        } else if (ans == 2) {
            //Remove a Task
            std::string title = "";
            cout << "Which Task would you like to REMOVE: ";
            getline(std::cin, title);

            TaskInterface *taskInterface = planner->wrap(title);
            if (taskInterface == nullptr) {
                //Given task does not exist
                cout << "\nTask does not exist." << endl;
            } else {
                //Task Exists
                if (planner->removeTask(*taskInterface)) {
                    cout << "Successfully removed.";
                } else {
                    cout << "Corrupted data!";
                }

            }


        } else if (ans == 3) {
            //View all reminders Menu
            planner->remind(std::cout);
        } else if (ans == 4) {
            //Editing a Task
            std::string title = "";
            cout << "\nWhich Task would you like to edit:";
            getline(std::cin, title);

            TaskInterface *taskInterface = planner->wrap(title);
            if (taskInterface == nullptr) {
                //Given task does not exist
                cout << "\nTask does not exist." << endl;
            } else {
                //Editing a Task Menu
                //Given Task exists
                std::string ansS = "";
                cout
                        << "\nWhat would you like to edit: \n1)Description\n2)Priority\n3)Due Date\n4)End Date\n5)Classification";
                getline(std::cin, ansS);
                int answer = stoi(ansS);

                if (answer == 1) {
                    //Editing Description of a Task
                    std::string desc = "";
                    cout << "\nChange description:";
                    getline(std::cin, desc);

                    taskInterface->setDescription(desc);
                } else if (answer == 2) {
                    //Editing the Priority of a Task
                    std::string priority = "\nChange priority:";
                    getline(std::cin, priority);

                    taskInterface->setPriority(std::stoi(priority));
                } else if (answer == 3) {
                    //Editing Due Date of a Task
                    std::string title = "\nChange due date:";
                    taskInterface->setDueDate(askUserForDueDateTime());
                } else if (answer == 4) {
                    //Editing End Date of a Task
                    std::string title = "\nChange end date:";
                    taskInterface->setEndDate(askUserForEndDateTime());

                } else if (answer == 5) {
                    std::string classificationS = "";
                    cout << "\nChange classification:";
                    getline(std::cin, classificationS);

                    Classification *classification = planner->getClassificationManager()->wrap(classificationS);
                    if (classification == nullptr) {
                        classification = new Classification(classificationS, "0xffffff");
                    }

                    planner->getClassificationManager()->addClassification(classification);

                    taskInterface->setClassification(classification);

                } else {


                }
            }
        } else if (ans == 5) {
            if (planner->undo()) {
                std::cout << "Undo was successful.";
            } else {
                std::cout << "Nothing left to undo.";
            }
        } else {

            cout << "\nTask Scheduler Program End" << endl;
            running = false;
        }

    } while (running);

    delete planner;
}
