#include "../include/NevigationHelper.h"

#include <algorithm>

using namespace std;

BaseFile* NevigationHelper::getBaseFileFromPath(FileSystem& fs, string path) {
	vector<string>* pathVector = splitPath(path);

	Directory* dir = &(fs.getWorkingDirectory());	
	int i		  = 0;

	if (path[0] == '/') {
		dir = &(fs.getRootDirectory());
	}
	else while ((*pathVector)[i] == "..") {
		dir = dir->getParent();
		i++;
	}

	BaseFile* tempFile = nullptr;
	int vectorSize = pathVector->size();

	while(i < vectorSize) {
		tempFile = dir->getFileByName((*pathVector)[i]);
		if (tempFile == nullptr) {
			delete pathVector;
			return nullptr;
		}
		if (tempFile->isFile()) {
			++i;
			break;
		}
		dir = (Directory*)(tempFile);
		++i;
	}
	delete pathVector;
	return i == vectorSize ? tempFile : nullptr;
}

vector<string>* NevigationHelper::splitPath(string path) {
	vector<string>* v = new vector<string>;

	while (path.size() > 0) {
		size_t slashPos = path.find_last_of("/");
		string dirName;

		if (slashPos == string::npos) {
			v->push_back(path);
			break;
		}

		dirName = path.substr(slashPos + 1);
		v->push_back(dirName);
		path.erase(slashPos);
	}

	reverse(v->begin(), v->end());
	return v;
}

Directory& NevigationHelper::getDeepestDirectoryInPath(FileSystem& fs, string path) {
	vector<string>* pathVector = splitPath(path);

	Directory* retDir = &(fs.getWorkingDirectory());
	size_t i = 0;

	if (path[0] == '/') {
		retDir = &(fs.getRootDirectory());
	}
	else while ((*pathVector)[i] == ".." && retDir != &(fs.getRootDirectory()) ) {
		retDir = retDir->getParent();
		i++;
	}

	BaseFile* tempFile;
	while (i < pathVector->size()) {
		tempFile = retDir->getFileByName((*pathVector)[i]);
		if (tempFile == nullptr || tempFile->isFile()) {
			break;
		}
		retDir = (Directory*)tempFile;
		++i;
	}

	delete pathVector;
	return *retDir;
}

string NevigationHelper::getAbsolutePath(FileSystem& fs, string path) {

	if (path[0] == '/') {
		return path;
	}

	string absPath;

	vector<string>* pathVector = splitPath(path);

	Directory dir = fs.getWorkingDirectory();
	int i = 0;

	while ((*pathVector)[i] == "..") {
		if (dir.getParent() == nullptr) {
			delete pathVector;
			return "Ilegal Path";
		}
		dir = *(dir.getParent());
		i++;
	}

	absPath = dir.getAbsolutePath();
	if (absPath != "/") {
		absPath += '/';
	}
	if (i > 0) {
		i--;
	}
	string temp = path.erase(0, 3 * i);
	if (temp.size() > 0) {
		absPath += temp;
	}
	delete pathVector;
	return absPath;
}