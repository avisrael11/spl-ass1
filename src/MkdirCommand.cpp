//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"
#include "../include/NevigationHelper.h"

#include <string>
#include <iostream>

using namespace std;


MkdirCommand::MkdirCommand(string args) : BaseCommand(args) {

}

void MkdirCommand::execute(FileSystem &fs) {
	NevigationHelper nh;
	string str			= getArgs();
	Directory wd		= nh.getDeepestDirectoryInPath(fs, str);
	string wdPath		= wd.getAbsolutePath();
	Errors err			= legalName(fs.getWorkingDirectory(), wd.getName());


	string path = nh.getAbsolutePath(str);
	vector<string> pathVector = nh.splitPath(path);
	vector<string>::iterator it;

	for (it = pathVector.begin(); it != pathVector.end(); it++) {
		BaseFile* bf = wd.getFileByName(*it);
		if (bf == nullptr) {
			createNewFolders(pathVector, it, wd);
			break;
		}
		else if (bf->isFile()) {
			err = FileExists;
			break;
		}
		wd = *((Directory*)bf);
	}

/*	for (it = pathVector.begin(); it != pathVector.end() ; it++){
		if (*it == wd.getName()) {
			while (*(++it) == wd.getName()) {
			}
			break;
		}
	}

	for (; it != pathVector.end(); it++){
		err = legalName(wd, *it);
		if (err == DirectoryAlreadyExists) {			
			cout << errorArray[err] << endl;
			break;
		}
		else if (err == FileExists) {
			break;
		}
		Directory* newDir = new Directory(*it, &wd);
		wd.addFile(newDir);
		wd = *newDir;
	}

	*/
/*
	for (vector<string>::iterator it = pathNameVector.begin(); it != pathNameVector.end(); ++it) {
		err = legal(fs.getWorkingDirectory());
		if (OK == err) {
			wd
		}

	}
	if (err == OK) {

		BaseFile* dir = new Directory(str, &(fs.getWorkingDirectory()));
		fs.getWorkingDirectory().addFile(dir);
	}
	else {
		cout << errorArray[err] << endl;
	}
	*/

	delete &pathNameVector;




	Directory* createPathIfLegal = &wd;

	if (str[0] == '/') {
		createPathIfLegal = &(fs.getRootDirectory());
	}
	else while (pathNameVector->back() == ".."){
		createPathIfLegal = createPathIfLegal->getParent();
		pathNameVector->pop_back();
	}

	BaseFile* tempFile;

	while(!pathNameVector->empty()){
		tempFile = createPathIfLegal->getFileByName(pathNameVector->back());
		if (tempFile == nullptr || tempFile->isFile()) {
			break;
		}
		createPathIfLegal = (Directory*)(tempFile);
		pathNameVector->pop_back();
	}

	if (pathNameVector->empty()) {
		err = DirectoryAlreadyExists;
	}
	else if(tempFile->isFile())	{
		err = FileExists;
	}
	else {
		while (!pathNameVector->empty()) {
			Directory* dir = new Directory(pathNameVector->back(), createPathIfLegal);
			createPathIfLegal->addFile(dir);
			createPathIfLegal = dir;
			pathNameVector->pop_back();
		}
	}

}

string MkdirCommand::toString() {
    return "mkdir";
}


MkdirCommand::Errors MkdirCommand::legalName(Directory &dir, string& dirName) {
	vector<BaseFile*> v = dir.getChildren();
	Errors ret = OK;

	for (vector<BaseFile*>::iterator it = v.begin(); it != v.end(); ++it) {
		if ((*it)->getName() == dirName) {
			if ( !((*it)->isFile()) )
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