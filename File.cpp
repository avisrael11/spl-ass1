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

