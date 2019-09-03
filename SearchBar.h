#pragma once
#include "TxtFileManager.h"
using namespace std;

class SearchBar
{
public:
	void openHistoryFile();
	void closeHistoryFile();
	void setKeyWords(const list<string>& keyWords);
	void writeKeyWordsToHistory();
	void autocompleteFromHistory(const string & partialKeyWord);
private:
	list<string> keyWords;
	string historyFile;
	ofstream historyFilePointerW;
	ifstream historyFilePointerR;
};

