#pragma once
#include "Report.h"
#include "FileManager.h"
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
	Report searchByName(const list<string>& keyWords); //cauta dupa numele fisierului
	Report searchByContent(const list<string>& listOfFiles, const string& word); //cauta dupa un cuvant dat in lista de fisiere gasite in configurare
	void findDensity(list<string> foundList, map<int, int> foundKeyWords);//ca param dau lista de fisiere in care am gasit cuvintele si mapa in care am nr total de cuv si nr de cuv cheie gasite
	void showReport(Report rep);
	list<string> bestRanking();
	list<string> getListForHistory();
private:
	list<string> mfoundList;//lista de fisiere in care am gasit cuvantul
	map<int, int> mfoundKeyWords;//numarul de cuvinte gasite in fisier si numarul de cuvinte totale din fisier
	list<string> mlistForHistory; //lista de cuvinte cautate, gasite in fisiere, trebuie puse in history
	map<float, string>mfileDensity;
	list<string> mtop5;
	SearchEngine() = default;
	SearchEngine(const SearchEngine&) = delete;
	static SearchEngine* instance;
};

