#include "SearchBar.h"
#include <iostream>
#include <list>
#include <string>
#include <conio.h>

int main()
{
	TxtFileManager txt;
	SearchBar bar;
	txt.openCfgFile();
	txt.searchList();
	bar.setKeyWords(txt.getListForHistory());
	bar.writeKeyWordsToHistory();
	txt.foundDensity();
	txt.bestRanking();
	txt.closeCfgFile();
}