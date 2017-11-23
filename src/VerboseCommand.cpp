//
// Created by Aviv Israel on 15/11/2017.
//

#include "../include/Commands.h"
#include "../include/VerboseHandler.h"

using namespace std;


VerboseCommand::VerboseCommand(string args) : BaseCommand(args) {
}

void VerboseCommand::execute(FileSystem &fs) {
	VerboseHandler vh;
	vh.setVerbose(stoul(getArgs()));

}

string VerboseCommand::toString() {
    return "verbose";
}
