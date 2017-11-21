//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"

#include <iostream>

using namespace std;

/*
class CdCommand : public BaseCommand {
private:
public:
    CdCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

CdCommand::CdCommand(string args) : BaseCommand(args) {

}

void CdCommand::execute(FileSystem &fs) {
	NevigationHelper nh;
	string path  = nh.getAbsolutePath(fs, getArgs());
	BaseFile* bf = nh.getBaseFileFromPath(fs, path);

	if (bf == nullptr || bf->isFile()) {
		cout << "The system cannot find the path specified" << endl;
		return;
	}
	fs.setWorkingDirectory((Directory*)bf);
}

string CdCommand::toString() {
    return "cd";
}
