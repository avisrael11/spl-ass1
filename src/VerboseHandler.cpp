//
//
//

#include "../include/VerboseHandler.h"

#include <iostream>

using namespace std;

VerboseHandler::VerboseHandler() : PRINTCOMMANDS(2), PRINTCOMMANDSANDFIVE(3), PRINTFIVE(1), MAXVAL(3){}

bool VerboseHandler::printCommands() {
	return (verbose == PRINTCOMMANDS || verbose == PRINTCOMMANDSANDFIVE);
}

bool VerboseHandler::printRule5() {
	return (verbose == PRINTFIVE || verbose == PRINTCOMMANDSANDFIVE);
}

void VerboseHandler::setVerbose(unsigned int val) {
	if (val <= MAXVAL) {
		verbose = val;
	}
	else
	{
		cout << "Wrong verbose input" << endl;
	}
}
