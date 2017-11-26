//
//
//mkfile – Create a new file. The path of the file must exists
//Syntax: mkfile <path/filename> <size>
//


#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>

using namespace std;

MkfileCommand::MkfileCommand(string args) : BaseCommand(args) {

}

void MkfileCommand::execute(FileSystem &fs) {
    NevigationHelper nh;
    string str              = getArgs();
    string path             = str.substr(0, str.find(' '));
    int size                = stoi(str.substr(path.length(), str.length()));

    Directory* wd           = &(fs.getRootDirectory());

    path = nh.getAbsolutePath(fs, path);
    vector<string>* pathVector = nh.splitPath(path);
    vector<string>::iterator it;
    for (it = pathVector->begin(); it != pathVector->end(); it++) {
        BaseFile* bf = wd->getFileByName(*it);
        if (bf == nullptr && it+1==pathVector->end()){
            //createNewFile(*pathVector, it, wd, size);
            File* newfile = new File(*it, size);
            wd->addFile(newfile);

            break;
        }
        else if (bf != nullptr && it+1==pathVector->end()){ //if the last bf exist
            cout << "File already exists" <<endl;
            break;
        }else if (bf == nullptr || bf->isFile()){ //if  bf non-exist or is file (and no equal to last)
            cout << "The system cannot find the path specified" <<endl;
            break;
        }

        wd = (Directory*)bf;
    }
    delete pathVector;
}

void MkfileCommand::createNewFile(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd, int size) {
        File* newfile = new File(*it, size);
        wd->addFile(newfile);

}

string MkfileCommand::toString() {
    return "mkfile";
}

MkfileCommand::~MkfileCommand() {

}

BaseCommand* MkfileCommand::clone(){
    return new MkfileCommand(getArgs());
}