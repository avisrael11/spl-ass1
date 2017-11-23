//
// Environment - Holds the file-system and the entire history of executed commands including
// duplicates, ErrorCommands and the HistoryCommands
//
//
#include "../include/Environment.h"
#include "../include/VerboseHandler.h"

#include <iostream>

using namespace std;

void printFS(Directory dir);

Environment::Environment(): commandsHistory(), fs(){
	
}

Environment::~Environment(){	
	for (vector<BaseCommand*>::iterator it = commandsHistory.begin(); it != commandsHistory.end(); it++) {
		delete *it;
	}
}

void Environment::start() {

    string command, args, fullLine;
    VerboseHandler vh;

    while (true){

        cout << fs.getWorkingDirectory().getAbsolutePath() << ">";
        getline(cin, fullLine, '\n');

        if (vh.printCommands()) {
            cout << fullLine << endl;
        }

        command = fullLine.substr(0, fullLine.find(' '));
        if (command.length()==fullLine.length())
            args = fullLine.substr(command.length(), fullLine.length());
        else
            args = fullLine.substr(command.length()+1, fullLine.length());


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
        }
        else if (command == "cd")
        {
            //cd commad
            BaseCommand* cdc = new CdCommand(args);
            cdc->execute(fs);
            addToHistory(cdc);
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
        else if (command == "exec")
        {
            //history command
            BaseCommand* historyc = new ExecCommand(args, commandsHistory);
            historyc->execute(fs);
            addToHistory(historyc);
        }
        else if (command == "verbose")
        {
            //verbose command
            BaseCommand* verboaeC = new VerboseCommand(args);
            verboaeC->execute(fs);
            addToHistory(verboaeC);
        }
        else
        {
            //Error command
            BaseCommand* errorc = new ErrorCommand(fullLine);
            errorc->execute(fs);
            addToHistory(errorc);
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
	for (auto &it : v) {
		cout << it->getName() << ", ";
	}
	cout << endl;
	
	for (auto &it : v) {
		if (!it->isFile()) {
			printFS( *( (Directory*) it) );
		}
	}


}