//
// verbose – Set the verbose variable as follows:
//  0 – verbose off (i.e. do not print 1, 2 or 3 below).
//  1 – Print a message in a new line each time entering a rule-of-five function. The message
//  must be the signature of the function in the format:
//  “return-type Class-Name:: Function-Name(full-argument-list)”
//  Example: “MyClass &MyClass::operator=(const MyClass &mc)”
//  2 – Echo/Print the full input command (with its arguments) to the screen followed by a new
//  line.
//  3 – Execute 1 and 2.
//  Syntax: verbose <0|1|2|3>
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

VerboseCommand::~VerboseCommand() {

}

BaseCommand* VerboseCommand::clone(){
	return new VerboseCommand(getArgs());
}
