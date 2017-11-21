#ifndef NEVIGATIONHELPER_H
#define NEVIGATIONHELPER_H

#include <vector>
#include <string>

#include "Files.h"
#include "FileSystem.h"

using namespace std;

class NevigationHelper
{
public:
	NevigationHelper() {};
	~NevigationHelper() {};

	BaseFile* getBaseFileFromPath(FileSystem& fs, string path);		 //Return target file if exist, nullptr otherwise
	vector<string>* splitPath(string path);			    		 	 //Split a string by '/' delimeter
	Directory& getDeepestDirectoryInPath(FileSystem& fs, string path);  //Return the last existing directory in path
	string getAbsolutePath(FileSystem& fs, string path);				 //Return absolute path from relative path


private:

};

#endif // !NEVIGATIONHELPER_H
