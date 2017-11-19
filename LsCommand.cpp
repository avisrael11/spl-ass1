//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class LsCommand : public BaseCommand {
private:
public:
    LsCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

LsCommand::LsCommand(string args) : BaseCommand(args) {

}

void LsCommand::execute(FileSystem &fs) {

}

string LsCommand::toString() {
    return std::string();
}
