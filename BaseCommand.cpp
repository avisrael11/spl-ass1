//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"

using namespace std;

BaseCommand::BaseCommand(string args): args(args) {

}

string BaseCommand::getArgs() {
    return args;
}
