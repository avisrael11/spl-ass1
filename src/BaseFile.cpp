//
// Created by Aviv Israel on 14/11/2017.
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


