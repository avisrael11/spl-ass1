//
// Created by Aviv Israel on 14/11/2017.
//
#include "../include/Files.h"

using namespace std;
/*
class File : public BaseFile {
private:
    int size;

public:
    File(string name, int size); // Constructor
    int getSize(); // Return the size of the file
    ~ File(); 	//Destructor
	File(const File &other);// Copy Constructor
	File(File &&other);// Move Constructor
	File& operator=(const File &other);// Copy Assignment
	File& operator=(File &&other);// Move Assignment

};
*/

File::File(string name, int size): BaseFile(name), size (size) {

}

int File::getSize() {
    return size;
}

bool File::isFile() {
	return false;
}

