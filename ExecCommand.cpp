//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class ExecCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    ExecCommand(string args, const vector<BaseCommand *> & history);
    void execute(FileSystem & fs);
    string toString();
};*/

ExecCommand::ExecCommand(string args, const vector<BaseCommand *> &history) : BaseCommand(args), history(history)  {

}

void ExecCommand::execute(FileSystem &fs) {

}

string ExecCommand::toString() {
    return std::string();
}
