//
// cp – Copy a file or directory to a destination.
//Syntax: cp <source-path> <destination-path>
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"

#include <iostream>

using namespace std;

CpCommand::CpCommand(string args) : BaseCommand(args) {

}

void CpCommand::execute(FileSystem &fs) {
    string arg		= getArgs();
    string source	= arg.substr(0, arg.find(' '));
    string dest		= arg.substr(source.length() + 1, arg.length());

    NevigationHelper nh;
    BaseFile* bfSource	= nh.getBaseFileFromPath(fs, source);
    BaseFile* bfDest	= nh.getBaseFileFromPath(fs, dest);

    if (bfSource != nullptr && bfDest != nullptr && !bfDest->isFile()) {
        string pathFileExistDest = ((Directory*)bfDest)->getAbsolutePath();
        if(pathFileExistDest != "/"){
            pathFileExistDest += '/';
        }
        pathFileExistDest += bfSource->getName();
        if(nh.getBaseFileFromPath(fs, pathFileExistDest) != nullptr){
            return;
        }

        BaseFile* newBaseFile;
        if (bfSource->isFile()) {
            newBaseFile = new File(*((File*)bfSource));
        }
        else {
            newBaseFile = new Directory(*((Directory*)bfSource));
        }
        ((Directory*)bfDest)->addFile(newBaseFile);
    }
    else {
        cout << "No such file or directory" << endl;
    }
}

string CpCommand::toString() {
    return "cp";
}

CpCommand::~CpCommand() {

}
