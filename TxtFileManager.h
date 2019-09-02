#pragma once
#include "FileManager.h"
class TxtFileManager :
	public FileManager
{
public:
	void openCfgFile();
	void searchList();
	void closeCfgFile();
	list<string> getListOfFiles();
	void foundDensity();
	void bestRanking();
	void upload();
	void download();

	map<float, string> fileDensity; //pastrez fisierul si densitatea 
	list<string> top5; //primele 5 fisiere cu densitatea cea mai mare

private:
	list<string> listOfFiles; //toate fisierele gasitein folderele din fisierul de configurare
	list<string> foundList; //toate fisierele in care am gasit cuvantul cautat
	map<int, int> foundKeyWords; //numarul de cuvinte gasite in fisier si numarul de cuvinte totale din fisier
};

