//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include <iostream>

using namespace std;
/*
class ErrorCommand : public BaseCommand {
private:
public:
    ErrorCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

ErrorCommand::ErrorCommand(string args) : BaseCommand(args) {

}

void ErrorCommand::execute(FileSystem &fs) {
    string command = getArgs().substr(0, getArgs().find(' '));
    cout << command << ": Unknown command" << endl;
}

string ErrorCommand::toString() {
    return "ErrorCommand";
}
