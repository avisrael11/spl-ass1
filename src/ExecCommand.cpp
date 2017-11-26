//
// exec – Executes a command from history.
// Syntax: exec <command-number>
//

#include "../include/Commands.h"
#include "iostream"

using namespace std;


ExecCommand::ExecCommand(string args, const vector<BaseCommand *> &history) : BaseCommand(args), history(history)  {

}

void ExecCommand::execute(FileSystem &fs) {
    string str              = getArgs();

    if (str.length()==0) {
        cout << "Command not found" << endl;
        return;
    }
    else {
        size_t size= stoi(str);
        if (size <= history.size()) {
            history[size]->execute(fs);
        }
        else
            cout << "Command not found" << endl;
    }
}

string ExecCommand::toString() {
    return "exec";
}

ExecCommand::~ExecCommand() {

}
