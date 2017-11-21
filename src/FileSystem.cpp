//
// Created by Aviv Israel on 14/11/2017.
//
#include "../include/FileSystem.h"
#include "../include/Files.h"

using namespace std;


/*
class FileSystem {
private:
    Directory* rootDirectory;
    Directory* workingDirectory;
public:
    FileSystem();
    Directory& getRootDirectory() const; // Return reference to the root directory
    Directory& getWorkingDirectory() const; // Return reference to the working directory
    void setWorkingDirectory(Directory *newWorkingDirectory); // Change the working directory of the file system


};*/

FileSystem::FileSystem():rootDirectory(new Directory("/", nullptr)), workingDirectory(rootDirectory)  {}
FileSystem:: ~FileSystem() {
	rootDirectory->deleteDir();
}


FileSystem::FileSystem(const FileSystem& other){
	rootDirectory = new Directory(other.getRootDirectory());
	workingDirectory = (Directory*)rootDirectory->getFileByName(other.getWorkingDirectory().getName());
}

FileSystem::FileSystem(FileSystem&& other){}


FileSystem& FileSystem::operator=(const FileSystem& other){
	if (this != &other) {
		rootDirectory->deleteDir();

		rootDirectory	 = new Directory(other.getRootDirectory());
		workingDirectory = (Directory*)rootDirectory->getFileByName(other.getWorkingDirectory().getName());
	}
	return *this;
}

FileSystem& FileSystem::operator=(FileSystem&& other){
	if (this != &other) {
		rootDirectory->deleteDir();
		rootDirectory    = other.rootDirectory;
		workingDirectory = other.workingDirectory;

		other.rootDirectory		= nullptr;
		other.workingDirectory  = nullptr;
	}
	return *this;
}

Directory &FileSystem::getRootDirectory() const {
    return *rootDirectory;
}

Directory &FileSystem::getWorkingDirectory() const {
    return *workingDirectory;
}

void FileSystem::setWorkingDirectory(Directory *newWorkingDirectory) {
    workingDirectory = newWorkingDirectory;
}

