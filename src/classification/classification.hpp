#ifndef CLASSIFICATION_HPP
#define CLASSIFICATION_HPP

#include <string>
#include <ostream>

class  Classification{
    private:
	std::string classificationName;
	std::string color;
    public:
	Classification();
	Classification(std::string name, std::string color)
	{
	    this->classificationName = name;
	    this->color = color;
	}

	std::string getName(){
	    return classificationName;
	}

	std::string getColor(){
	    return color;
	}

	void setName(std::string name){
	    this->classificationName = name;
	}
	
	void setColor(std::string color){
	    this->color = color;
	}

	bool operator==(const Classification &classification){
	    return this->classificationName == classification.classificationName;
	}

	friend std::ostream& operator<<(std::ostream& os, const Classification& classification)
	{
	    os << classification.classificationName;
	    return os;
	}

};

#endif
