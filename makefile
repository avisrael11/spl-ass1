# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
LFLAGS  = -L/usr/lib

# All Targets
all: fs

# Tool invocations
# Executable "fs" depends on the files below
fs: bin/BaseCommand.o bin/BaseFile.o bin/CdCommand.o bin/CpCommand.o bin/Directory.o bin/Enviroment.o bin/ErrorCommand.o bin/ExecCommand.o bin/File.o bin/FileSystem.o bin/HistoryCommand.o LsCommand.o bin/main.o bin/MkdirCommand.o bin/MkfileCommand.o bin/MvCommand.o bin/NevigationHelper.o bin/PwdCommand.o bin/RenameCommand.o bin/RmCommand.o bin/VerboseCommand.o bin/VerboseHandler.o
	@echo 'Building target: fs'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/fs bin/BaseCommand.o bin/BaseFile.o bin/CdCommand.o bin/CpCommand.o bin/Directory.o bin/Enviroment.o bin/ErrorCommand.o bin/ExecCommand.o bin/File.o bin/FileSystem.o bin/HistoryCommand.o LsCommand.o bin/main.o bin/MkdirCommand.o bin/MkfileCommand.o bin/MvCommand.o bin/NevigationHelper.o bin/PwdCommand.o bin/RenameCommand.o bin/RmCommand.o bin/VerboseCommand.o $(LFLAGS)
	@echo 'Finished building target: fs'
	@echo ' '

# Depends on the source and header files - BaseCommand
bin/BaseCommand.o: src/BaseCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/BaseCommand.o src/BaseCommand.cpp

# Depends on the source and header files - BaseFile
bin/BaseFile.o: src/BaseFile.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/BaseFile.o src/BaseFile.cpp

# Depends on the source and header files - CdCommand
bin/CdCommand.o: src/CdCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/CdCommand.o src/CdCommand.cpp

# Depends on the source and header files - CpCommand
bin/CpCommand.o: src/CpCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/CpCommand.o src/CpCommand.cpp

# Depends on the source and header files - Directory
bin/Directory.o: src/Directory.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Directory.o src/Directory.cpp

# Depends on the source and header files - Enviroment
bin/Enviroment.o: src/Enviroment.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Enviroment.o src/Enviroment.cpp

# Depends on the source and header files - ErrorCommand
bin/ErrorCommand.o: src/ErrorCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/ErrorCommand.o src/ErrorCommand.cpp

# Depends on the source and header files - ExecCommand
bin/ExecCommand.o: src/ExecCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/ExecCommand.o src/ExecCommand.cpp

# Depends on the source and header files - File
bin/File.o: src/File.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/File.o src/File.cpp

# Depends on the source and header files - FileSystem
bin/FileSystem.o: src/FileSystem.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/FileSystem.o src/FileSystem.cpp

# Depends on the source and header files - HistoryCommand
bin/HistoryCommand.o: src/HistoryCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/HistoryCommand.o src/HistoryCommand.cpp

# Depends on the source and header files - LsCommand
bin/LsCommand.o: src/LsCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/LsCommand.o src/LsCommand.cpp

# Depends on the source and header files - main
bin/main.o: src/main.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/main.o src/main.cpp

# Depends on the source and header files - MkdirCommand
bin/MkdirCommand.o: src/MkdirCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/MkdirCommand.o src/MkdirCommand.cpp

# Depends on the source and header files - MkfileCommand
bin/MkfileCommand.o: src/MkfileCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/MkfileCommand.o src/MkfileCommand.cpp

# Depends on the source and header files - MvCommand
bin/MvCommand.o: src/MvCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/MvCommand.o src/MvCommand.cpp

# Depends on the source and header files - NevigationHelper
bin/NevigationHelper.o: src/NevigationHelper.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/NevigationHelper.o src/NevigationHelper.cpp

# Depends on the source and header files - PwdCommand
bin/PwdCommand.o: src/PwdCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/PwdCommand.o src/PwdCommand.cpp

# Depends on the source and header files - RenameCommand
bin/RenameCommand.o: src/RenameCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/RenameCommand.o src/RenameCommand.cpp

# Depends on the source and header files - RmCommand
bin/RmCommand.o: src/RmCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/RmCommand.o src/RmCommand.cpp

# Depends on the source and header files - VerboseCommand
bin/VerboseCommand.o: src/VerboseCommand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/VerboseCommand.o src/VerboseCommand.cpp

# Depends on the source and header files - VerboseHandler
bin/VerboseHandler.o: src/VerboseHandler.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/VerboseHandler.o src/VerboseHandler.cpp

#Clean the build directory
clean:
	rm -f bin/*
