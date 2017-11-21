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
    ~FileSystem(); 	//Destructor
    FileSystem(const FileSystem &other);// Copy Constructor
    FileSystem(FileSystem &&other);// Move Constructor
    FileSystem& operator=(const FileSystem &other);// Copy Assignment
    FileSystem& operator=(FileSystem &&other);// Move Assignment
    Directory& getRootDirectory() const; // Return reference to the root directory
    Directory& getWorkingDirectory() const; // Return reference to the working directory
    void setWorkingDirectory(Directory *newWorkingDirectory); // Change the working directory of the file system


};*/

FileSystem::FileSystem():rootDirectory(new Directory("/", nullptr)), workingDirectory(rootDirectory)  {

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

