//
// Environment - Holds the file-system and the entire history of executed commands including
// duplicates, ErrorCommands and the HistoryCommands
//
//
#include "../include/Environment.h"
#include "../include/VerboseHandler.h"

#include <iostream>

using namespace std;


Environment::Environment(): commandsHistory(), fs(){
	
}

Environment::~Environment(){
    VerboseHandler vh;
    if(vh.printRule5()){
        cout << "Environment::~Environment()" << endl;
    }
	for (vector<BaseCommand*>::iterator it = commandsHistory.begin(); it != commandsHistory.end(); it++) {
		delete *it;
	}
}

Environment::Environment(const Environment &other): commandsHistory(), fs(other.fs){
    VerboseHandler vh;
    if(vh.printRule5()){
        cout << "Environment::Environment(const Environment &other)" << endl;
    }

    copyHistory(other.getHistory());

}


Environment::Environment(Environment &&other): commandsHistory(other.commandsHistory), fs(other.fs){
}


Environment& Environment::operator=(const Environment &other){
    if(this != &other){
        for (vector<BaseCommand*>::iterator it = commandsHistory.begin(); it != commandsHistory.end(); it++) {
            delete *it;
        }
        fs = other.fs;
        copyHistory(other.getHistory());
    }
    return *this;
}

Environment& Environment::operator=(Environment &&other){
    if(this != &other){
        for (vector<BaseCommand*>::iterator it = commandsHistory.begin(); it != commandsHistory.end(); it++) {
            delete *it;
        }
        fs = other.fs;
        copyHistory(other.getHistory());

    }
    return *this;
}


void Environment::start() {

    string command, args, fullLine;
    VerboseHandler vh;

    while (true){

        cout << fs.getWorkingDirectory().getAbsolutePath() << ">";
        getline(cin, fullLine, '\n');

        if (vh.printCommands() && fullLine != "exit") {
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
            BaseCommand* exec = new ExecCommand(args, commandsHistory);
            exec->execute(fs);
            addToHistory(exec);
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

void Environment::copyHistory(const vector<BaseCommand*>& otherHistory){
    for(vector<BaseCommand*>::const_iterator it = otherHistory.begin(); it != otherHistory.end(); ++it){
        if((*it)->toString() == "exec" ){
            commandsHistory.push_back(new ExecCommand((*it)->getArgs(), commandsHistory));
        }
        else if((*it)->toString() == "history" ){
            commandsHistory.push_back(new HistoryCommand((*it)->getArgs(), commandsHistory));
        }
        else{
            commandsHistory.push_back((*it)->clone());
        }
    }


}