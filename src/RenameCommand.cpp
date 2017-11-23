//
// rename – Rename a file or a directory.
// Syntax: rename <path/old-name> <new-name>
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include <iostream>


using namespace std;

RenameCommand::RenameCommand(string args) : BaseCommand(args) {

}

void RenameCommand::execute(FileSystem &fs) {
    string arg		= getArgs();
    string oldName	= arg.substr(0, arg.find(' '));
    string newNmae	= arg.substr(oldName.length()+1, arg.length());

    NevigationHelper nh;
    BaseFile* bfOldName	= nh.getBaseFileFromPath(fs, oldName);


    if (bfOldName != nullptr) // if oldName == file or directory exist
    {
        if (!bfOldName->isFile() && fs.getWorkingDirectory().getAbsolutePath() == (*(Directory*)bfOldName).getAbsolutePath())  //if directory and equal working Directory
            cout << "Can’t rename the working directory" << endl;
        else
            bfOldName->setName(newNmae);
    }
    else {
        cout << "No such file or directory" << endl;
    }
}

string RenameCommand::toString() {
    return std::string();
}
