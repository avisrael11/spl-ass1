#ifndef VERBOSEHANDLER_H
#define VERBOSEHANDLER_H

#include "../include/GlobalVariables.h"

using namespace std;

class VerboseHandler
{
public:

	VerboseHandler();

	bool printCommands();
	bool printRule5();
	void setVerbose(unsigned int val);

private:
	const unsigned int PRINTCOMMANDS;
	const unsigned int PRINTCOMMANDSANDFIVE;
	const unsigned int PRINTFIVE;

	const unsigned int MAXVAL;
};
#endif // VERBOSEHANDLER_H
