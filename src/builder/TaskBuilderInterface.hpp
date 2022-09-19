#ifndef _TASKBUILDERINTERFACE_HPP_
#define _TASKBUILDERINTERFACE_HPP_

#include <string>

class TaskInterface;
class Planner;

class TaskBuilderInterface {
	protected:
		std::string title;
		Planner* planner;
		friend class TaskDirector;

	public:
		TaskBuilderInterface(std::string title) : title(title) {};
		virtual void buildDescription() = 0;
		virtual void buildClassification() = 0;
		virtual void buildPriority() = 0;
		virtual void buildDueDate() = 0;
		virtual void buildEndDate() = 0;
		virtual TaskInterface* getTask() = 0;
};

#endif
