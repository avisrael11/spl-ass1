
#include "../include/NevigationHelper.h"


using namespace std;

BaseFile* NevigationHelper::getBaseFileFromPath(FileSystem& fs, string path) {
	if (path == "/") {
		return &(fs.getRootDirectory());
	}

	vector<string>* pathVector = splitPath(path);

	Directory* dir = &(fs.getWorkingDirectory());	
	int i		   = 0;
	int vectorSize = pathVector->size();

	if (path[0] == '/') {
		dir = &(fs.getRootDirectory());
	}
	else while (i < vectorSize && (*pathVector)[i] == "..") {
		dir = dir->getParent();
		i++;
	}

	BaseFile* tempFile = nullptr;

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
	else while (i < pathVector->size() && (*pathVector)[i] == ".." && retDir != &(fs.getRootDirectory()) ) {
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
	size_t i = 0;

	while (i < pathVector->size() && (*pathVector)[i] == "..") {
		if (dir.getParent() == nullptr) {
			delete pathVector;
			return "Ilegal Path";
		}
		dir = (*(dir.getParent()));
		i++;
	}

	absPath = dir.getAbsolutePath();
	string temp = path.erase(0, 3 * i);
	if (temp.size() > 0) {
		if (absPath != "/"){
			absPath += '/';
		}
		absPath += temp;
	}
	delete pathVector;
	return absPath;
}

bool NevigationHelper::isPathLegit(FileSystem& fs, string path) {
	string absPath				= getAbsolutePath(fs, path);
	vector<string>* pathVector  = splitPath(absPath);
	BaseFile* bf				= &(fs.getRootDirectory());
	bool ret					= true;

	for (vector<string>::iterator it = pathVector->begin(); it != pathVector->end(); ++it) {
		if (bf->isFile()) {
			if (++it == pathVector->end()) {
				ret = true;
			}else{
				ret = false;
			}

			break;
		}
		
		vector<BaseFile*> children = ((Directory*)bf)->getChildren();
		for (vector<BaseFile*>::iterator bfIt = children.begin(); bfIt != children.end(); ++bfIt) {
			if ((*bfIt)->getName() == *it) {
				bf = *bfIt;
				break;
			}
			if (bfIt + 1 == children.end()) {
				delete pathVector;
				return false;
			}
		}
	} 
		delete pathVector;
		return ret;
}