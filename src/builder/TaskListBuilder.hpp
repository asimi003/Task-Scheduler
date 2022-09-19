#ifndef _TASKLISTBUILDER_HPP_
#define _TASKLISTBUILDER_HPP_

#include "TaskBuilderInterface.hpp"

class TaskList;

class TaskListBuilder : public TaskBuilderInterface {
	private: 
		TaskList* taskList;
	public:
	
	TaskListBuilder(std::string);
	//virtual void buildTitle();
	virtual void buildDescription() override;
	virtual void buildClassification() override;
	virtual void buildPriority() override;
	virtual void buildDueDate() override;
	virtual void buildEndDate() override;
	virtual TaskInterface *getTask() override;
};

#endif
