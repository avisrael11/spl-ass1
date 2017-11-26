//
// ls: Display the list of files and subdirectories of a directory
// Syntax:  ls [-s] <path> - Display the list of files and subdirectories in <path>
//          ls [-s] - Display the list of files and subdirectories in the working directory
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>

using namespace std;

LsCommand::LsCommand(string args) : BaseCommand(args), isLss(false) {

}

void LsCommand::execute(FileSystem &fs) {
    NevigationHelper nh;
    string str = getArgs();
    if (str.compare(0, 2, "-s") == 0)//if there is argument [-s]
    {
        isLss = true;
        if (str.length()<3)
            str.clear();
        else
            str = str.substr(3, str.length());
    }
    else {
        isLss = false;

    }

    if (str.length() == 0)//if don't get <path> as argument => <path>==" "
    {
        str = fs.getWorkingDirectory().getAbsolutePath();
    }
    else {
        if(!nh.isPathLegit(fs, str)) {
            cout << "The system cannot find the path specified" << endl;
            return;
        }

    }

    string path = nh.getAbsolutePath(fs, str);
    Directory* lsDir = &(nh.getDeepestDirectoryInPath(fs, path));//getBaseFileFromPath(FileSystem& fs, string path)
    lsDir->sortByName();
    if (isLss)
        lsDir->sortBySize();

    vector<BaseFile*> childrenVector = lsDir->getChildren();
    for (auto &it : childrenVector) {
        if(it->isFile())
            cout << "FILE\t" ;
        else
            cout << "DIR\t";
        cout << it->getName() << "\t";
        cout << it->getSize() << endl;
    }
}

string LsCommand::toString() {
    return "ls";
}

LsCommand::~LsCommand() {

}

BaseCommand* LsCommand::clone(){
    return new LsCommand(getArgs());
}
