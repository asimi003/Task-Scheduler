#include "TaskList.h"

using std::setw;

TaskList::TaskList(std::string title) : TaskInterface(title) {}

bool TaskList::addSubtask(TaskInterface* taskInterface)
{
    //Inserts to task set.
    if(!this->taskList.insert(taskInterface).second)
    {
        return false;
    }
    return true;
}

bool TaskList::removeSubtask(TaskInterface* taskInterface)
{
    //remove
    if(this->taskList.erase(taskInterface) != 1)
    {
        return false;
    }
    return true;
}

bool TaskList::hasSubtask(TaskInterface* taskInterface)
{
    return this->taskList.find(taskInterface) != taskList.end();

}

void TaskList::remindTask(std::ostream& os) const {
    std::streamsize SPACE = 3;

    os << std::setfill(' ');
    os << std::left;


    //setw is set to [123] | 5 characters
    os << "[" << setw(SPACE) << this->getPriority() << "] ";

    //setw is set to largest Classification
    const unsigned int classNameLength = 7;
    bool isClassNameLong = this->getClassification()->getName().size() > classNameLength;
    os << "(" << setw(classNameLength) << this->getClassification()->getName().substr(0, classNameLength) << (isClassNameLong ? "...)" : ")") << " ";

    //substr should be first 15 chars
    const unsigned int size_title = 15;
    bool isTitleLarger = this->getTitle().size() > size_title;
    os << "\"" << setw(size_title) << (this->getTitle().substr(0, size_title) + (isTitleLarger ? "..." : "")) << "\" ";

    //substr should be first 25 chars
    const unsigned int size_desc = 22;
    bool isDescriptionBigger = this->getDescription().size() > size_desc;
    os << "\"" << setw(size_desc) << this->getDescription().substr(0, size_desc)
       << (isDescriptionBigger ? "..." : "") << "\" ";

    char *dueDateCString = ctime(&dueDate);
    std::string dueDateString(dueDateCString);
    dueDateString.resize(dueDateString.size() - 1);

    os << "\"" << setw(SPACE) << dueDateString << "\"" << " ";

    char *endDateCString = ctime(&endDate);
    std::string endDateString(endDateCString);
    endDateString.resize(endDateString.size() - 1);

    os << "\"" << setw(SPACE)  << endDateString << "\"";

    os << "\n";


    for(TaskInterface* taskInterface : this->taskList)
    {
        std::streamsize SPACE = 3;

        os << std::setfill(' ');
        os << std::left;


        //setw is set to [123] | 5 characters
        os << "[" << setw(SPACE) << taskInterface->getPriority() << "] ";

        //setw is set to largest Classification
        const unsigned int classNameLength = 7;
        bool isClassNameLong = taskInterface->getClassification()->getName().size() > classNameLength;
        os << "(" << setw(classNameLength) << taskInterface->getClassification()->getName().substr(0, classNameLength) << (isClassNameLong ? "...)" : ")") << " ";

        //substr should be first 15 chars
        const unsigned int size_title = 15;
        bool isTitleLarger = taskInterface->getTitle().size() > size_title;
        os << "\"" << setw(size_title) << (taskInterface->getTitle().substr(0, size_title) + (isTitleLarger ? "..." : "")) << "\" ";

        //substr should be first 25 chars
        const unsigned int size_desc = 22;
        bool isDescriptionBigger = taskInterface->getDescription().size() > size_desc;
        os << "\"" << setw(size_desc) << taskInterface->getDescription().substr(0, size_desc)
           << (isDescriptionBigger ? "..." : "") << "\" ";

        time_t dueDate = taskInterface->getDueDate();
        char *dueDateCString = ctime(&dueDate);
        std::string dueDateString(dueDateCString);
        dueDateString.resize(dueDateString.size() - 1);

        os << "\"" << setw(SPACE) << dueDateString << "\"" << " ";

        time_t endDate = taskInterface->getEndDate();
        char *endDateCString = ctime(&endDate);
        std::string endDateString(endDateCString);
        endDateString.resize(endDateString.size() - 1);

        os << "\"" << setw(SPACE)  << endDateString << "\"";

        os << "\n";

    }

}
