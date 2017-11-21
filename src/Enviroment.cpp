//
// Created by Aviv Israel on 13/11/2017.
//
#include "../include/Environment.h"
#include "../include/Files.h"
#include "../include/Commands.h"
#include "../include/FileSystem.h"

#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

void printFS(Directory dir);
Environment::Environment() {
	
}

Environment::~Environment(){	
	for (vector<BaseCommand*>::iterator it = commandsHistory.begin(); it != commandsHistory.end(); it++) {
		delete *it;
	}
}

void Environment::start() {
    string input;
	map<string, int> commandsMap;

    cout << "Hello:) ";

    while ( input != "exit") {
        cout << ">";
		cin >> input;

		if (input == "mkdir") {
			BaseCommand* mkdir = new MkdirCommand("name1/name2/name3");
			mkdir->execute(fs);
			addToHistory(mkdir);
		}
		else if (input == "history") {
			BaseCommand* history = new HistoryCommand("", commandsHistory);
			history->execute(fs);
			addToHistory(history);
		}
		else if (input == "pwd") {
			BaseCommand* pwd = new PwdCommand("");
			pwd->execute(fs);
			addToHistory(pwd);
		}
		else if (input == "cd") {
			BaseCommand* cd = new CdCommand("name1");
			cd->execute(fs);
			addToHistory(cd);
		}

    }
}

FileSystem& Environment::getFileSystem(){
	
    return fs;
}

void Environment::addToHistory(BaseCommand *command) {
	commandsHistory.push_back(command);
}

const vector<BaseCommand *> &Environment::getHistory() const {
    return commandsHistory;
}

void printFS(Directory dir) {	
	vector<BaseFile*> v = dir.getChildren();

	cout << dir.getName() << endl;
	for (vector<BaseFile*>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it)->getName() << ", ";
	}
	cout << endl;
	
	for (vector<BaseFile*>::iterator it = v.begin(); it != v.end(); ++it) {
		if (!(*it)->isFile()) {
			printFS( *( (Directory*)(*it) ) );
		}
	}


}