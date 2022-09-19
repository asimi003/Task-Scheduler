#ifndef CLASSIFICATION_MANAGER_HPP
#define CLASSIFICATION_MANAGER_HPP

#include "classification.hpp"
#include <set>

#include <iostream>

class ClassificationManager {
private:
    std::set<Classification *> classificationsSet;

public:
    ClassificationManager();

    ~ClassificationManager() {
        for (Classification *taskInterface: classificationsSet) {
            delete taskInterface;
        }
    }

    bool addClassification(Classification *type);

    bool removeClassification(Classification *type);

    bool hasClassification(Classification *type);

    Classification *wrap(std::string keyword);
};


#endif //CLASSIFICATION_MANAGER_HPP

