#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <string>
#include "FileSystem.h"
#include <array>
//ddd


class BaseCommand {
private:
    string args;

public:
    BaseCommand(string args);
	virtual ~BaseCommand();
    string getArgs();
    virtual void execute(FileSystem & fs) = 0;
    virtual string toString() = 0;
	virtual BaseCommand* clone() = 0;
};

class PwdCommand : public BaseCommand {
private:
public:
    PwdCommand(string args);
	virtual ~PwdCommand();
    void execute(FileSystem & fs); // Every derived class should implement this function according to the document (pdf)
    virtual string toString();
	virtual BaseCommand* clone();
};

class CdCommand : public BaseCommand {
private:
public:
    CdCommand(string args);
	virtual ~CdCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class LsCommand : public BaseCommand {
private:
	bool isLss;
public:
    LsCommand(string args);
	virtual ~LsCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class MkdirCommand : public BaseCommand {
private:
	void createNewFolders(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd);
public:
    MkdirCommand(string args);
	virtual ~MkdirCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class MkfileCommand : public BaseCommand {
private:
	void createNewFile(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd, int size);
public:
    MkfileCommand(string args);
	virtual ~MkfileCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class CpCommand : public BaseCommand {
private:
public:
    CpCommand(string args);
	virtual ~CpCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class MvCommand : public BaseCommand {
private:
public:
    MvCommand(string args);
	virtual ~MvCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class RenameCommand : public BaseCommand {
private:
public:
    RenameCommand(string args);
	virtual ~RenameCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class RmCommand : public BaseCommand {
private:
public:
    RmCommand(string args);
	virtual ~RmCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class HistoryCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    HistoryCommand(string args, const vector<BaseCommand *> & history);
	virtual ~HistoryCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};


class VerboseCommand : public BaseCommand {
private:
public:
    VerboseCommand(string args);
	virtual ~VerboseCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class ErrorCommand : public BaseCommand {
private:
public:
    ErrorCommand(string args);
	virtual ~ErrorCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();
};

class ExecCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    ExecCommand(string args, const vector<BaseCommand *> & history);
	virtual ~ExecCommand();
    void execute(FileSystem & fs);
    string toString();
	virtual BaseCommand* clone();

};


#endif