//
// BaseFile – This is an abstract class for File and Directory.
//
#include "../include/Files.h"

using namespace std;

BaseFile::BaseFile(string name) : name(name){


}


string BaseFile::getName() const {
    return name;
}

void BaseFile::setName(string newName) {
    name = newName;
}

bool BaseFile::compareByName(BaseFile *lhs, BaseFile *rhs) { return lhs->getName() < rhs->getName(); }

bool BaseFile::compareBySize(BaseFile *lhs, BaseFile *rhs) { return lhs->getSize() < rhs->getSize(); }




