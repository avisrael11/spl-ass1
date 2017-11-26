//
// mkdir – Create a new directory. If needed, create intermediate directories in the path.
// Syntax: mkdir <path>
//
#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>

using namespace std;


MkdirCommand::MkdirCommand(string args) : BaseCommand(args) {

}

void MkdirCommand::execute(FileSystem &fs) {
	NevigationHelper nh;
	string str = getArgs();
	Directory* wd = &(fs.getRootDirectory());
	bool dirCreated = false;

	string path = nh.getAbsolutePath(fs, str);
	vector<string>* pathVector = nh.splitPath(path);
	vector<string>::iterator it;

	for (it = pathVector->begin(); it != pathVector->end(); it++) {
		BaseFile* bf = wd->getFileByName(*it);
		if (bf == nullptr) {
			createNewFolders(*pathVector, it, wd);
			dirCreated = true;
			break;
		}
		else if (bf->isFile()) {
			break;
		}
		wd = (Directory*)bf;
	}
	if (!dirCreated) {
		cout << "The directory already exists" << endl;
	}

	delete pathVector;
}

string MkdirCommand::toString() {
	return "mkdir";
}


void MkdirCommand::createNewFolders(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd) {
	for (; it != pathVector.end(); ++it) {
		Directory* newDir = new Directory(*it, wd);
		wd->addFile(newDir);
		wd = newDir;
	}
}

MkdirCommand::~MkdirCommand() {

}

BaseCommand* MkdirCommand::clone(){
        return new MkdirCommand(getArgs());
}

