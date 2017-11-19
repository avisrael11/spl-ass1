//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class RenameCommand : public BaseCommand {
private:
public:
    RenameCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

RenameCommand::RenameCommand(string args) : BaseCommand(args) {

}

void RenameCommand::execute(FileSystem &fs) {

}

string RenameCommand::toString() {
    return std::string();
}
