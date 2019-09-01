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
			size_t found = filename.find(".txt");
			if (found != string::npos)
			{
				std::cout << filename << std::endl;
				listOfFiles.push_back(filename);
			}
		}
	}
}

void TxtFileManager::searchList()
{
	fstream srcFilePointer;
	string search;
	string line;
	cout << "enter word to search for: ";
	cin >> search;

	for (auto file : listOfFiles)
	{
		srcFilePointer.open(file);

		if (!srcFilePointer)
		{
			cout << "Unable to open file" << endl;
			exit(1);
		}

		size_t pos;
		while (srcFilePointer.good())
		{
			getline(srcFilePointer, line); // get line from file
			pos = line.find(search); // search
			if (pos != string::npos) // string::npos is returned if string is not found
			{
				cout << "Found!";
				break;
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
	return listOfFiles;
}

void TxtFileManager::upload()
{
}

void TxtFileManager::download()
{
}

