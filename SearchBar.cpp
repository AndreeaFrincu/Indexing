#include "SearchBar.h"

void SearchBar::openHistoryFile()
{
	historyFile = "history.txt";
	historyFilePointerR.open(historyFile);
	historyFilePointerW.open(historyFile, ios::app);

	if (!historyFilePointerR)
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}
}

void SearchBar::closeHistoryFile()
{
	historyFilePointerR.close();
	historyFilePointerW.close();
}

void SearchBar::setKeyWords(const list<string>& keyWords)
{
	this->keyWords = keyWords;
}

void SearchBar::writeKeyWordsToHistory()
{
	string line;
	size_t pos;

	openHistoryFile();
	getline(historyFilePointerR, line);
	for (auto word : keyWords)
	{
		pos = line.find(word);
		if (pos != string::npos)
		{
			break;
		}
		else 
		{
			historyFilePointerW << word << endl;
		}
	}
	closeHistoryFile();
}
