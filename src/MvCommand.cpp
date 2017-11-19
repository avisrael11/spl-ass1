//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class MvCommand : public BaseCommand {
private:
public:
    MvCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

MvCommand::MvCommand(string args) : BaseCommand(args) {

}

void MvCommand::execute(FileSystem &fs) {

}

string MvCommand::toString() {
    return std::string();
}
