//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include "../include/Files.h"

#include <iostream>

using namespace std;

MvCommand::MvCommand(string args) : BaseCommand(args) {
}

void MvCommand::execute(FileSystem &fs) {
	string arg		= getArgs();
	string source	= arg.substr(0, arg.find(' '));
	string dest		= arg.substr(source.length() + 1, arg.length());

	NevigationHelper nh;
	BaseFile* bfSource	= nh.getBaseFileFromPath(fs, source);
	BaseFile* bfDest	= nh.getBaseFileFromPath(fs, dest);

	if (bfSource == &fs.getRootDirectory() || ( fs.getWorkingDirectory().getParent() != nullptr && bfSource == fs.getWorkingDirectory().getParent()) || bfSource == &fs.getWorkingDirectory()) {
		cout << "Can't move directory" << endl;
		return;
	}
	else if (bfSource == nullptr || bfDest == nullptr || bfDest->isFile()) {
		cout << "No such file or directory" << endl;
		return;
	}
	if (bfSource->isFile()) {
		nh.getDeepestDirectoryInPath(fs, source).removeFile(bfSource);
	}
	else {
		((Directory*)bfSource)->getParent()->removeFile(bfSource);
	}
	((Directory*)bfDest)->addFile(bfSource);
}
 
string MvCommand::toString(){
    return "mv";
}

MvCommand::~MvCommand() {

}

