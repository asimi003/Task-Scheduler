#include <classification/classificationManager.hpp>
#include <builder/TaskBuilder.hpp>
#include <builder/TaskDirector.hpp>
#include <builder/TaskListBuilder.hpp>
#include "tasks/TaskList.h"
#include "tasks/Task.h"
#include <planner/Planner.h>
#include "gtest/gtest.h"
#include <string>
#include <sstream>


TEST(ClassificationSuite, ClassificationAdd) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");

    EXPECT_EQ(true, classificationManager->addClassification(classification));
}


TEST(ClassificationSuite, ClassificationNoAdd) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");
    classificationManager->addClassification(classification);

    EXPECT_EQ(false, classificationManager->addClassification(classification));
}

TEST(ClassificationSuite, ClassificationContains) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");
    classificationManager->addClassification(classification);
    EXPECT_EQ(true, classificationManager->hasClassification(classification));
}

TEST(ClassificationSuite, ClassificationNoContains) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");
    classificationManager->addClassification(classification);
    EXPECT_EQ(false, classificationManager->hasClassification(new Classification("School", "0xfff232")));
}

TEST(ClassificationSuite, ClassificationRemove) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");
    classificationManager->addClassification(classification);
    EXPECT_EQ(true, classificationManager->removeClassification(classification));
}

TEST(ClassificationSuite, ClassificationNoRemove) {
    ClassificationManager *classificationManager = new ClassificationManager();
    Classification *classification = new Classification("Work", "0xfff232");
    classificationManager->addClassification(classification);
    EXPECT_EQ(false, classificationManager->removeClassification(new Classification("School", "0xfff232")));
}


TEST(BuilderSuite, BuilderCheckTaskList) {
    Planner *planner = new Planner;

    TaskListBuilder *taskListBuilder = new TaskListBuilder("3 Labs");

    TaskDirector *taskDirector = new TaskDirector(planner, taskListBuilder);

    taskDirector->constructTask();
    TaskInterface *labsTask = taskDirector->getTask();

    bool isTaskList = false;
    if (dynamic_cast<TaskList *>(labsTask))
        isTaskList = true;

    EXPECT_EQ(true, isTaskList);
}

TEST(BuilderSuite, BuilderCheckTask) {
    Planner *planner = new Planner;

    TaskBuilder *taskBuilder = new TaskBuilder("3 Labs");

    TaskDirector *taskDirector = new TaskDirector(planner, taskBuilder);

    taskDirector->constructTask();
    TaskInterface *labsTask = taskDirector->getTask();

    bool isTask = false;
    if (dynamic_cast<Task *>(labsTask))
        isTask = true;

    EXPECT_EQ(true, isTask);
}

TEST(TaskSuite, TaskInterfaceSetValues) {
    Task *task = new Task("TaskTitle");

    Classification *classification = new Classification("School", "0x424343");
    task->setClassification(classification);

    unsigned int priority = 5;
    task->setPriority(priority);

    task->setEndDate(0);
    task->setDueDate(0);

    task->setDescription("DESC");

    EXPECT_EQ(true, task->getTitle() == "TaskTitle" && task->getDescription() == "DESC" && task->getEndDate() == 0 && task->getDueDate() == 0 && task->getPriority() == priority && task->getClassification() == classification);
}

TEST(PlannerSuite, Undo1)
{
    Planner* planner = new Planner();

    Task* task = new Task("Title");
    planner->addTask(*task);

    planner->undo();

    EXPECT_EQ(false, planner->hasTask(*task));

}

TEST(PlannerSuite, Undo2)
{
    Planner* planner = new Planner();

    Task* task = new Task("Title");
    planner->addTask(*task);
    Task* task2 = new Task("Title2");

    planner->addTask(*task);
    planner->addTask(*task2);

    planner->undo();
    planner->undo();

    EXPECT_EQ(true, !planner->hasTask(*task) && !planner->hasTask(*task2));

}

TEST(PlannerSuite, Undo3)
{
    Planner* planner = new Planner();

    Task* task = new Task("Title");
    planner->addTask(*task);

    task->setDescription("YouFoundMe");
    task->setDescription("UndoShouldntSeeThis");
    planner->undo();

    TaskInterface* taskHidden = planner->wrap(task->getTitle());


    EXPECT_EQ("YouFoundMe", taskHidden->getDescription());

}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

