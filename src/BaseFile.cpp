//
// Created by Aviv Israel on 14/11/2017.
//
#include "../include/Files.h"
/*
class BaseFile {
private:
    string name;

public:
    BaseFile(string name);

    virtual ~ BaseFile(); 	//Destructor
    BaseFile(const BaseFile &other);// Copy Constructor
    BaseFile(BaseFile &&other);// Move Constructor
    BaseFile& operator=(const BaseFile &other);// Copy Assignment
    BaseFile& operator=(BaseFile &&other);// Move Assignment

    string getName() const;
    void setName(string newName);
    virtual int getSize() = 0;

    virtual bool isFile() = 0;
};*/


using namespace std;

BaseFile::BaseFile(string name) : name(name){


}

/*
// Copy Constructor
BaseFile::BaseFile(const BaseFile &other) {

}

BaseFile::BaseFile(BaseFile &&other) {

}

BaseFile &BaseFile::operator=(const BaseFile &other) {
    return <#initializer#>;
}

BaseFile &BaseFile::operator=(BaseFile &&other) {
    return <#initializer#>;
}
*/


string BaseFile::getName() const {
    return name;
}

void BaseFile::setName(string newName) {
    name = newName;
}

bool BaseFile::compareByName(BaseFile *lhs, BaseFile *rhs) { return lhs->getName() < rhs->getName(); }

bool BaseFile::compareBySize(BaseFile *lhs, BaseFile *rhs) { return lhs->getSize() < rhs->getSize(); }





