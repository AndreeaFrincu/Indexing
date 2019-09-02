#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class SearchBar
{
public:
	void openHistoryFile();
	void closeHistoryFile();
	list<string> getKeyWords();
	void writeKeyWordsToHistory();
	void autocompleteFromHistory(const string & partialKeyWord);
private:
	list<string> keyWords;
	string historyFile;
	fstream historyFilePointer;
};

