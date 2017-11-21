//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;

/*
class CdCommand : public BaseCommand {
private:
public:
    CdCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

CdCommand::CdCommand(string args) : BaseCommand(args) {

}

void CdCommand::execute(FileSystem &fs) {

}

string CdCommand::toString() {
    return std::string();
}
