#include "SearchBar.h"

void SearchBar::openHistoryFile()
{
	historyFile = "history.txt";
	historyFilePointer.open(historyFile);

	if (!historyFilePointer)
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}
}

void SearchBar::closeHistoryFile()
{
	historyFilePointer.close();
}

list<string> SearchBar::getKeyWords()
{
	return list<string>();
}
