
#include "../include/Files.h"
#include <algorithm>
#include <iostream>

using namespace std;

Directory::Directory(string name, Directory *parent) : BaseFile(name), parent(parent){
	if (parent != nullptr) {
		depth = parent->getDepth() + 1;
	}

	cout << "directory constractor: " << getName() << endl;
}

Directory::~Directory() {
	if (verbose == 1) {
		cout << "directory destractor: " << getName() << endl;
	}
}

Directory::Directory(const Directory &other): BaseFile(other.getName()), parent(other.getParent()) {
	copyChildren(other);
}
Directory::Directory(Directory &&other) : BaseFile(other.getName()), parent(other.getParent()) {
	copyChildren(other);

	other.deleteDir();
}

Directory& Directory::operator=(const Directory &other) {
	if (this != &other) {
		if (parent != nullptr) {
			parent->removeFile(this);
		}
		for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
			removeFile(*it);
		}

		copyChildren(other);
		parent = other.getParent();
		setName(other.getName());			
	}
	return *this;
}

Directory& Directory::operator=(Directory &&other) {
	if (this != &other) {
		if (parent != nullptr) {
			parent->removeFile(this);
		}
		for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
			removeFile(*it);
		}

		copyChildren(other);
		parent = other.getParent();
		setName(other.getName());

		other.deleteDir();
	}
	return *this;
}

void Directory::deleteDir() {
	for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if (!(*it)->isFile()) {
			((Directory*)(*it))->deleteDir();
			delete (*it);
		}
	}
	if (parent != nullptr) {
		parent->removeFile(this);
		parent = nullptr;
	}
}

Directory *Directory::getParent() const {
    return parent;
}

int Directory::getDepth() {
	return depth;
}

void Directory::setParent(Directory *newParent) {
    parent = newParent;

}

bool Directory::isFile() {
	return false;
}

void Directory::addFile(BaseFile *file) {
	if (file != NULL) {
		children.push_back(file);
	}
}

void Directory::removeFile(string name) {
    for(vector<BaseFile*>::iterator iterator1 = children.begin(); iterator1 != children.end(); ++iterator1){
        if((*iterator1)->getName() == name){
            children.erase(iterator1);
			break;
        }
    }
}

void Directory::removeFile(BaseFile *file) {
    if(file != NULL) {
        removeFile(file->getName());
    }
}

void Directory::sortByName() {
    sort(children.begin(), children.end(), compareByName);

}
void Directory::sortBySize() {
    sort(children.begin(), children.end(), compareBySize);

}

vector<BaseFile *> Directory::getChildren() {
    return children;
}

int Directory::getSize() {
    int totalSize = 0;
    for(vector<BaseFile*>::iterator iterator1 = children.begin(); iterator1 != children.end(); ++iterator1){
        totalSize += (*iterator1)->getSize();
    }
    return totalSize;
}

string Directory::getAbsolutePath() {
    string absolutePath;

    if(parent == nullptr){		
		return "/";
    }

	absolutePath = parent->getAbsolutePath();
	if (absolutePath != "/") {
		return absolutePath + "/" + getName();
	}
    return absolutePath + getName();
}

bool Directory::isContainDirectory(string fileName) {
	for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if ((*it)->getName() == fileName && !(*it)->isFile()) {
			return true;
		}
	}
	return false;
}

bool Directory::isContainFile(string fileName) {
	for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		if ((*it)->getName() == fileName && (*it)->isFile()) {
			return true;
		}
	}
	return false;
}

BaseFile* Directory::getFileByName(string fileName) {
	if (fileName.size() == 0) {
		return this;
	}

	for (vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
		//string s = (*it)->getName();
		if ((*it)->getName() == fileName ) {
			return *it;
		}
	}
	return nullptr;
}

void Directory::copyChildren(const Directory& other) {
	vector<BaseFile*> ch = other.children;

	for (vector<BaseFile*>::iterator it = ch.begin(); it != ch.end(); ++it) {
		BaseFile* newBf;

		if ((*it)->isFile()) {
			newBf = new File((*it)->getName(), (*it)->getSize());
		}
		else {
			newBf = new Directory(*((Directory*)(*it)));
		}
		children.push_back(newBf);
	}
}

bool compareByName(BaseFile *lhs, BaseFile *rhs) {
	return lhs->getName() < rhs->getName();
}

bool compareBySize(BaseFile *lhs, BaseFile *rhs) {
	return lhs->getSize() < rhs->getSize();
}