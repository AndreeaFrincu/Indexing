#pragma once
#include "FileManager.h"
class TxtFileManager :
	public FileManager
{
public:
	void openCfgFile();
	void closeCfgFile();
	list<string> getListOfFiles();
	void upload();
	void download();

private:
	list<string> listOfFiles;
};

