//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

#include <iostream>

using namespace std;
/*
class PwdCommand : public BaseCommand {
private:
public:
    PwdCommand(string args);
    void execute(FileSystem & fs); // Every derived class should implement this function according to the document (pdf)
    virtual string toString();
};*/

PwdCommand::PwdCommand(string args) : BaseCommand(args) {

}

void PwdCommand::execute(FileSystem &fs) {
	cout << fs.getWorkingDirectory().getAbsolutePath() << endl;
}

string PwdCommand::toString() {
    return "pwd";
}
