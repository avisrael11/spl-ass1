//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"

using namespace std;

/*
class HistoryCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    HistoryCommand(string args, const vector<BaseCommand *> & history);
    void execute(FileSystem & fs);
    string toString();
};*/

HistoryCommand::HistoryCommand(string args, const vector<BaseCommand *> &history) : BaseCommand(args), history(history) {

}

void HistoryCommand::execute(FileSystem &fs) {

}

string HistoryCommand::toString() {
    return std::string();
}
