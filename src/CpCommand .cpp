//
// cp – Copy a file or directory to a destination.
//Syntax: cp <source-path> <destination-path>
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
