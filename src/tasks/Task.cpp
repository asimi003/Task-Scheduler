#include "Task.h"
#include <sstream>
#include "../classification/classification.hpp"
#include <string>

using std::setw;

Task::Task(std::string title) : TaskInterface(title) {}

void Task::remindTask(std::ostream &os) const {


    std::streamsize SPACE = 3;

    os << std::setfill(' ');
    os << std::left;


    //setw is set to [123] | 5 characters
    os << "[" << setw(SPACE) << this->getPriority() << "] ";

    //setw is set to largest Classification
    const unsigned int classNameLength = 7;
    Classification* classification1 = this->getClassification();
    bool isClassNameLong = classification1->getName().size() > classNameLength;
    os << "(" << setw(classNameLength) << classification1->getName().substr(0, isClassNameLong ? classNameLength : classification1->getName().size()) << (isClassNameLong ? "...)" : ")") << " ";

    //substr should be first 15 chars
    const unsigned int size_title = 15;
    bool isTitleLarger = this->getTitle().size() > size_title;
    os << "\"" << setw(size_title) << (this->getTitle().substr(0, isTitleLarger ? size_title : this->getTitle().size()) + (isTitleLarger ? "..." : "")) << "\" ";

    //substr should be first 25 chars
    const unsigned int size_desc = 22;
    bool isDescriptionBigger = this->getDescription().size() > size_desc;
    os << "\"" << setw(size_desc) << this->getDescription().substr(0, isDescriptionBigger ? size_desc : this->getDescription().size())
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


}
