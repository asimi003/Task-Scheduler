#include "TaskBuilderInterface.hpp"

class Task;

class TaskBuilder : public TaskBuilderInterface
{
	private:
		Task* task;
	public:
	    TaskBuilder(std::string title);
	    virtual void buildDescription() override;
	    virtual void buildClassification() override;
	    virtual void buildPriority() override;
	    virtual void buildEndDate() override;
	    virtual void buildDueDate() override;
	    virtual TaskInterface* getTask() override;

};
