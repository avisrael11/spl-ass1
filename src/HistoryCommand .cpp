//
// Created by Aviv Israel on 15/11/2017.
//
#include "../include/Commands.h"

#include <iostream>

using namespace std;

/*
class HistoryCommand : public BaseCommand {
private:
const vector<BaseCommand *> & history;
public:
HistoryCommand(string args, const vector<BaseCommand *> & history);
void execute(FileSystem & fs);
string toString();
};*/

HistoryCommand::HistoryCommand(string args, const vector<BaseCommand *> &history) : BaseCommand(args), history(history) {

}

void HistoryCommand::execute(FileSystem &fs) {
	size_t i = 0;
	while (i < history.size()) {
		cout << i << "	" << history[i]->toString() << " " << history[i]->getArgs() << endl;
		++i;
	}

}

string HistoryCommand::toString() {
	return "history";
}
