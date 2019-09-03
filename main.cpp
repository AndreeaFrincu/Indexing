#include "SearchBar.h"
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include "SearchEngine.h"

int main()
{
	TxtFileManager txt;
	SearchBar bar;
	SearchEngine* Engine = SearchEngine::getInstance();	
	string str;

	txt.openCfgFile();
	Engine->showReport(Engine->searchByContent(txt.getListOfFiles(), str));
	bar.setKeyWords(Engine->getListForHistory());
	bar.writeKeyWordsToHistory();
	//Engine->bestRanking();
	txt.closeCfgFile();
}