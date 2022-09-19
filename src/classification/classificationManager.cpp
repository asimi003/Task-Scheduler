#include "classificationManager.hpp"

#include <set>

ClassificationManager::ClassificationManager()
{
    Classification* classification = new Classification("Unnamed", "0xffffff");
    if(!this->classificationsSet.insert(classification).second)
        delete classification;
}

/**
 * Adds a Classification to the set.
 * @param type The classification to add
 * @returns true if Classification was added
 *     returns false if a Classification already exists
 */
bool ClassificationManager::addClassification(Classification* type){
    //Inserts to task set
    if(!this->classificationsSet.insert(type).second)
    {
	return false;
    }

    //If insert successful
    return true;

}

/**
 * Removes classification from set
 * @param type The classification to remove
 * @return true if removed, false if not found in set
 */
bool ClassificationManager::removeClassification(Classification* type){
    //remove
    if(this->classificationsSet.erase(type) != 1)
    {
        delete type;
	return false;
    }
    delete type;
    return true;   
}

/**
 * Checks to see if classification exists in set
 * @param type The classification to check
 * @return true if found in set, false if not found
 */
bool ClassificationManager::hasClassification(Classification* type){
    return this->classificationsSet.find(type) != classificationsSet.end();
}


/**
 * Wraps name of classification into ClassificationManager
 * @param nameOfClassification The name of classification we are looking for
 * @return Classification* if name of classification is found in set, nullptr if not found
 */
Classification* ClassificationManager::wrap(std::string keyword){
    for(Classification* classification : this->classificationsSet)
        if(classification->getName() == keyword)
	    return classification;
    return nullptr;
}
