#include "TxtFileManager.h"

void TxtFileManager::openCfgFile()
{
	cfgFilePointer.open("cfgFile.txt");
	cout << "reading paths from cfg file..." << endl;
	for (string line; getline(cfgFilePointer, line);)
	{
		cout << "folderul curent " << line << " contine:" << endl;
		string path = line;
		string path2 = line;
		string filename;
		for (const auto& entry : fs::directory_iterator(path))
		{
			filename = entry.path().filename().string();
			size_t found = filename.find(".txt");
			if (found != string::npos)
			{
				std::cout << filename << std::endl;
			}
		}
	}
}

void TxtFileManager::closeCfgFile()
{
	cfgFilePointer.close();
}

list<string> TxtFileManager::getListOfFiles()
{
	return list<string>();
}

void TxtFileManager::upload()
{
}

void TxtFileManager::download()
{
}
