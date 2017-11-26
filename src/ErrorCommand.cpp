//
// ErrorCommand – This is a special command class that represents an unknown command, that is,
// a command that is not listed in the commands list below. It also inherits from BaseCommand.
// When executed it prints: "<the-input-command>: Unknown command”
//

#include "../include/Commands.h"
#include <iostream>

using namespace std;

ErrorCommand::ErrorCommand(string args) : BaseCommand(args) {

}

void ErrorCommand::execute(FileSystem &fs) {
    string command = getArgs().substr(0, getArgs().find(' '));
    cout << command << ": Unknown command" << endl;
}

string ErrorCommand::toString() {
    return "";
}

ErrorCommand::~ErrorCommand() {

}

BaseCommand* ErrorCommand::clone(){
    return new ErrorCommand(getArgs());
}