//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class VerboseCommand : public BaseCommand {
private:
public:
    VerboseCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

VerboseCommand::VerboseCommand(string args) : BaseCommand(args) {

}

void VerboseCommand::execute(FileSystem &fs) {

}

string VerboseCommand::toString() {
    return std::string();
}
