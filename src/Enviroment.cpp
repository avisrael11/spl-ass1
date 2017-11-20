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


Environment::Environment() {
	
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
		}
		cout << fs.getRootDirectory().getChildren().back() << endl;

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
