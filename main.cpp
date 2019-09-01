#include "TxtFileManager.h"
#include <iostream>
#include <list>
#include <string>
#include <conio.h>

int main()
{
	TxtFileManager txt;
	txt.openCfgFile();
	int size = txt.getListOfFiles().size();
	cout << size << endl;
	txt.searchList();
	txt.closeCfgFile();
}