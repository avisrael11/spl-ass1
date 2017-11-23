//
// File – Inherits from BaseFile. This class represents a single file in the system. Each file has a
//  name, a size and a parent (the containing directory).
//
#include "../include/Files.h"

using namespace std;

File::File(string name, int size): BaseFile(name), size (size) {

}

int File::getSize() {
    return size;
}

bool File::isFile() {
	return true;
}

