//
// BaseCommand – This is an abstract class for the different command classes
//
#include "../include/Commands.h"

using namespace std;

BaseCommand::BaseCommand(string args): args(args) {

}

string BaseCommand::getArgs() {
    return args;
}

BaseCommand::~BaseCommand() {

}
