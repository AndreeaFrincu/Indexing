#include "TxtFileManager.h"

void TxtFileManager::openCfgFile()
{
	cfgFilePointer.open("cfgFile.txt");

	if (!cfgFilePointer)
	{
		cout << "Unable to open file" << endl;
		exit(1);
	}

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
			//cout << filename << endl;
			path2 = entry.path().string();
			size_t found = filename.find(".txt");
			if (found != string::npos)
			{
				std::cout << filename << std::endl;
				listOfFiles.push_back(path2);
			}
		}
	}
}


list<string> TxtFileManager::getListOfFiles()
{
	return this->listOfFiles;
}

void TxtFileManager::upload()
{
}

void TxtFileManager::download()
{
}

void TxtFileManager::closeCfgFile()
{
	cfgFilePointer.close();
}


