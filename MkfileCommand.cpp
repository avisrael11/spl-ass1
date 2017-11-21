//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class MkfileCommand : public BaseCommand {
private:
public:
    MkfileCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

MkfileCommand::MkfileCommand(string args) : BaseCommand(args) {

}

void MkfileCommand::execute(FileSystem &fs) {

}

string MkfileCommand::toString() {
    return std::string();
}
