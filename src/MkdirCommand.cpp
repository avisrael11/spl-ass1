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
	//Errors err = OK;

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
			//err = FileExists;
			break;
		}
		wd = (Directory*)bf;
	}
	if (!dirCreated) {
		cout << "Directory Already Exists" << endl;
	}

	delete pathVector;
}

string MkdirCommand::toString() {
	return "mkdir";
}

/*
MkdirCommand::Errors MkdirCommand::legalName(Directory &dir, string& dirName) {
	vector<BaseFile*> v = dir.getChildren();
	Errors ret = OK;

	for (vector<BaseFile*>::iterator it = v.begin(); it != v.end(); ++it) {
		if ((*it)->getName() == dirName) {
			if (!((*it)->isFile()))
				ret = DirectoryAlreadyExists;
			else
				ret = FileExists;
		}
	}
	return ret;
}


string MkdirCommand::extractName(string str) {

	size_t nameStart = str.find_last_of("/");

	if (nameStart != string::npos) {
		return str.substr(nameStart);
	}
	return str;
}
*/

void MkdirCommand::createNewFolders(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd) {
	for (; it != pathVector.end(); ++it) {
		Directory* newDir = new Directory(*it, wd);
		wd->addFile(newDir);
		wd = newDir;
	}
}