//
// Created by Aviv Israel on 13/11/2017.
// v1.0
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

    string command, args;

    while (true){

        cout << ">";
        cin >> command;
        cin.ignore();
        getline(cin, args, '\n');

        if (command == "exit")
        {
            return;
        }
        else if (command == "pwd")
        {
            //pwd commad
            BaseCommand* pwdc = new PwdCommand(args);
            pwdc->execute(fs);
            addToHistory(pwdc);
            //cout << "pwd commad" << endl;

        }
        else if (command == "cd")
        {
            //cd commad
            BaseCommand* cdc = new CdCommand(args);
            cdc->execute(fs);
            addToHistory(cdc);
            //cout << "cd commad" << endl;
        }
        else if (command == "ls")
        {
            //ls command
            BaseCommand* lsc = new LsCommand(args);
            lsc->execute(fs);
            addToHistory(lsc);

        }
        else if (command == "mkdir")
        {
            //mkdir command
            BaseCommand* mkdirc = new MkdirCommand(args);
            mkdirc->execute(fs);
            addToHistory(mkdirc);

        }
        else if (command == "mkfile")
        {
            //mkfile command
            BaseCommand* mkfilec = new MkfileCommand(args);
            mkfilec->execute(fs);
            addToHistory(mkfilec);

        }
        else if (command == "cp")
        {
            //cp command
            BaseCommand* cpc = new CpCommand(args);
            cpc->execute(fs);
            addToHistory(cpc);

        }
        else if (command == "mv")
        {
            //mv command
            BaseCommand* mvc = new MvCommand(args);
            mvc->execute(fs);
            addToHistory(mvc);

        }
        else if (command == "rename")
        {
            //rename command
            BaseCommand* renamec = new RenameCommand(args);
            renamec->execute(fs);
            addToHistory(renamec);
        }
        else if (command == "rm")
        {
            //rm command
            BaseCommand* rmc = new RmCommand(args);
            rmc->execute(fs);
            addToHistory(rmc);

        }
        else if (command == "history")
        {
            //history command
            BaseCommand* historyc = new HistoryCommand("", commandsHistory);
            historyc->execute(fs);
            addToHistory(historyc);

        }
        else
        {
            //Error command
            string fullcomand = command + " " + args;
            BaseCommand* errorc = new ErrorCommand(fullcomand);
            errorc->execute(fs);
            addToHistory(errorc);
        }

    }

}
 /*
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
 */

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