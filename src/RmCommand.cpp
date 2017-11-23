//
// rm – Remove (delete) a file or a directory. If the argument is a directory remove it
//recursively.
//	Syntax: rm <path>
//
#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>

using namespace std;


RmCommand::RmCommand(string args) : BaseCommand(args) {

}

void RmCommand::execute(FileSystem &fs) {
	string path = getArgs();

	NevigationHelper nh;
	BaseFile* toRemove = nh.getBaseFileFromPath(fs, path);

	if (toRemove == nullptr) {
		cout << "No such file or directory" << endl;
		return;
	}
	if (toRemove->isFile()) {
		nh.getDeepestDirectoryInPath(fs, path).removeFile(toRemove);
	}
	else if(toRemove == &(fs.getWorkingDirectory()) || toRemove == fs.getWorkingDirectory().getParent() || toRemove == &(fs.getRootDirectory()) ) {
		cout << "Can't remove directory" << endl;
	}
	else{
		((Directory*)toRemove)->getParent()->removeFile(toRemove);
		((Directory*)toRemove)->deleteDir();
	}
	delete toRemove;
}

string RmCommand::toString() {
    return "rm";
}

RmCommand::~RmCommand() {

}

