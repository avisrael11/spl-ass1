//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"

using namespace std;
/*
class ErrorCommand : public BaseCommand {
private:
public:
    ErrorCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};*/

ErrorCommand::ErrorCommand(string args) : BaseCommand(args) {

}

void ErrorCommand::execute(FileSystem &fs) {

}

string ErrorCommand::toString() {
    return std::string();
}
