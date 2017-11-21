//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;

/*
class CpCommand : public BaseCommand {
private:
public:
    CpCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

CpCommand::CpCommand(string args) : BaseCommand(args) {

}

void CpCommand::execute(FileSystem &fs) {

}

string CpCommand::toString() {
    return std::string();
}
