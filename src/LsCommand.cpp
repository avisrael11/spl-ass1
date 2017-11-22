//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>

using namespace std;


LsCommand::LsCommand(string args) : BaseCommand(args) {

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

    } else
    {
       /*******check valid path ***/
        /***If <path> doesn’t exist print out “The system cannot find the path specified”***/
    }

    string path = nh.getAbsolutePath(fs, str);
    Directory lsDir = nh.getDeepestDirectoryInPath(fs, path);//getBaseFileFromPath(FileSystem& fs, string path)
    lsDir.sortByName();
    if (isLss)
        lsDir.sortBySize();

    vector<BaseFile*> childrenVector = lsDir.getChildren();
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