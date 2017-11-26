//
// history – Print out the entire list of the executed commands sorted from the oldest to the
// newest, excluding current history command.
//
#include "../include/Commands.h"
#include <iostream>

using namespace std;

HistoryCommand::HistoryCommand(string args, const vector<BaseCommand *> &history) : BaseCommand(args), history(history) {

}

void HistoryCommand::execute(FileSystem &fs) {
    size_t i = 0;
    while (i < history.size()) {
        if(history[i]->toString() != "") {
            cout << i << "	" << history[i]->toString() << " " << history[i]->getArgs() << endl;
        }
        else{
            cout << i << "	" << history[i]->getArgs() << endl;
        }
        ++i;
    }
}

string HistoryCommand::toString() {
    return "history";
}

HistoryCommand::~HistoryCommand() {

}
