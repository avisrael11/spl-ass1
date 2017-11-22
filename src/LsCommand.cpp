//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <string>
#include <iostream>

using namespace std;
/*
class LsCommand : public BaseCommand {
private:
public:
    LsCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

LsCommand::LsCommand(string args) : BaseCommand(args) {

}

void LsCommand::execute(FileSystem &fs) {


    NevigationHelper nh;
    string str = getArgs();
    //Directory* wd = &(fs.getRootDirectory());
    //Errors err = OK;


    if (str.compare(0, 2, "-s") == 0)//if there is argument [-s]
    {
        isLss = true;
        str = str.substr(3, str.length());
        //cout << "if s" << str<< endl;
    }
    else {
        isLss = false;
        //cout << "no s" << str<< endl;
    }

    string path = nh.getAbsolutePath(fs, str);
    cout << path << endl;
    cout << "ok" << endl;
 //   vector<string>* pathVector = nh.splitPath(path);
/*
    vector<string>::iterator it;
    // for (it = pathVector->begin(); it != pathVector->end(); it++) {
    for (it = pathVector->begin(), it != pathVector->end(), it++) {
        BaseFile* bf = wd->getFileByName(*it);
        if (bf == nullptr)
            //createNewFolders(*pathVector, it, wd);
            //dirCreated = true;
            break;
        }
        else if (bf->isFile()) {
            err = FileExists;
            break;
        }
        wd = (Directory*)bf;
    }
    if (!dirCreated) {
        cout << "Directory Already Exists" << endl;
    }

    delete pathVector;
*/

    //Directory lsDir = nh.getDeepestDirectoryInPath(fs, path);//getBaseFileFromPath(FileSystem& fs, string path)
    //lsDir.sortByName();
    //if (isLss)
    //    lsDir.sortBySize();
    /*
    vector<BaseFile*> childrenVector = lsDir.getChildren();
    for (vector<BaseFile*>::iterator it = childrenVector.begin(); it != childrenVector.end(); ++it) {
        cout <<(*it)->getName() << endl;


    }*/
    //cout<< lsDir.<< endl;
}

string LsCommand::toString() {
    return "ls";
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

void MkdirCommand::createNewFolders(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd) {
    for (; it != pathVector.end(); ++it) {
        Directory* newDir = new Directory(*it, wd);
        wd->addFile(newDir);
        wd = newDir;
    }
}
 */