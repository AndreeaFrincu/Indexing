#pragma once
#include <filesystem>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctype.h>

namespace fs = std::filesystem;
using namespace std;

class FileManager
{
public:
	virtual void openCfgFile() = 0;
	virtual void closeCfgFile() = 0;
	virtual list<string> getListOfFiles() = 0;
	virtual void upload() = 0;
	virtual void download() = 0;

	string rootFile;
	fstream cfgFilePointer;
	//fstream srcFilePointer;
};

