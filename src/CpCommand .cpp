//
// cp – Copy a file or directory to a destination.
//Syntax: cp <source-path> <destination-path>
//

#include "../include/Commands.h"
#include "../include/NevigationHelper.h"
#include "../include/Files.h"

#include <iostream>

using namespace std;

/*
class CpCommand : public BaseCommand {
private:
public:
    CpCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

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
		cout << "" << endl;
	}
}

string CpCommand::toString() {
    return "cp";
}
