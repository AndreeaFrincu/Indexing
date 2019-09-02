#include "TxtFileManager.h"
#include <iostream>
#include <list>
#include <string>
#include <conio.h>

int main()
{
	TxtFileManager txt;
	txt.openCfgFile();
	txt.searchList();
	txt.foundDensity();
	txt.bestRanking();
	txt.closeCfgFile();
}