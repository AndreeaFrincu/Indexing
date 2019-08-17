#pragma once
#include "Report.h"
#include <list>
#include <string>

using namespace std;

class SearchEngine
{
public:
	static SearchEngine* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new SearchEngine;
		}
		return instance;
	};
	Report searchByName(const list<string>& keyWords);
	Report searchByContent(const list<string>& keyWords);
private:
	SearchEngine() = default;
	SearchEngine(const SearchEngine&) = delete;
	static SearchEngine* instance;
};

