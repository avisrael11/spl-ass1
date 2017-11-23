//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include "../include/Files.h"

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
	else {
		((Directory*)toRemove)->getParent()->removeFile(toRemove);
		((Directory*)toRemove)->deleteDir();
	}
	delete toRemove;
}

string RmCommand::toString() {
    return "rm";
}

