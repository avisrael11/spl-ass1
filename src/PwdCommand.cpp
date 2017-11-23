//
// pwd - print working directory path.
//

#include "../include/Commands.h"
#include <iostream>

using namespace std;

PwdCommand::PwdCommand(string args) : BaseCommand(args) {

}

void PwdCommand::execute(FileSystem &fs) {
	cout << fs.getWorkingDirectory().getAbsolutePath() << endl;
}

string PwdCommand::toString() {
    return "pwd";
}

PwdCommand::~PwdCommand() {

}
