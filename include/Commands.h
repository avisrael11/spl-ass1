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
    string getArgs();
    virtual void execute(FileSystem & fs) = 0;
    virtual string toString() = 0;
};

class PwdCommand : public BaseCommand {
private:
public:
    PwdCommand(string args);
    void execute(FileSystem & fs); // Every derived class should implement this function according to the document (pdf)
    virtual string toString();
};

class CdCommand : public BaseCommand {
private:
public:
    CdCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class LsCommand : public BaseCommand {
private:
	bool isLss;
public:
    LsCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class MkdirCommand : public BaseCommand {
private:
	typedef enum
	{
		OK,
		DirectoryAlreadyExists,
		FileExists
	}Errors;

	array<std::string, 3> errorArray = { "OK", "The directory already exists", "Ther is a file with the same name" };
	Errors legalName(Directory &dir, string& dirName);
	string extractName(string str);
	void createNewFolders(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd);

public:
    MkdirCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class MkfileCommand : public BaseCommand {
private:
	void createNewFile(vector<string>& pathVector, vector<string>::iterator& it, Directory* wd, int size);
public:
    MkfileCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class CpCommand : public BaseCommand {
private:
public:
    CpCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class MvCommand : public BaseCommand {
private:
public:
    MvCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class RenameCommand : public BaseCommand {
private:
public:
    RenameCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class RmCommand : public BaseCommand {
private:
public:
    RmCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class HistoryCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    HistoryCommand(string args, const vector<BaseCommand *> & history);
    void execute(FileSystem & fs);
    string toString();
};


class VerboseCommand : public BaseCommand {
private:
public:
    VerboseCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class ErrorCommand : public BaseCommand {
private:
public:
    ErrorCommand(string args);
    void execute(FileSystem & fs);
    string toString();
};

class ExecCommand : public BaseCommand {
private:
    const vector<BaseCommand *> & history;
public:
    ExecCommand(string args, const vector<BaseCommand *> & history);
    void execute(FileSystem & fs);
    string toString();
};


#endif