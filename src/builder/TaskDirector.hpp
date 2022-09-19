#ifndef _TASKDIRECTOR_HPP_
#define _TASKDIRECTOR_HPP_

class TaskBuilderInterface;
class Planner;
class TaskInterface;

class TaskDirector{
        private:
                TaskBuilderInterface* taskBuilder;
		Planner* planner;

        public:
                TaskDirector(Planner* planner, TaskBuilderInterface* taskBuilderInterface);
		void constructTask();
		TaskInterface* getTask();
};
		
#endif
