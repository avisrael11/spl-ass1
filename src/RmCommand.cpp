//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"

using namespace std;

/*class RmCommand : public BaseCommand {
private:
public:
    RmCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};
*/

RmCommand::RmCommand(string args) : BaseCommand(args) {

}

void RmCommand::execute(FileSystem &fs) {

}

string RmCommand::toString() {
    return std::string();
}

