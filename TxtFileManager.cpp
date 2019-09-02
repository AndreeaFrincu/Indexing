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

void TxtFileManager::searchList()
{
	fstream hstFilePointer;
	fstream srcFilePointer;
	string search;
	string line;//linie din fisierul in care caut
	string line1;//linie din fisierul de istoric
	int nrCuv = 0;
	bool found1 = false;

	cout << "enter word to search for: ";
	cin >> search;
	transform(search.begin(), search.end(), search.begin(), ::tolower);
	//cout << "..............." << search << endl;

	for (auto file : listOfFiles)
	{
		srcFilePointer.open(file);

		if (!srcFilePointer)
		{
			cout << "Unable to open file" << endl;
			exit(1);
		}

		size_t pos;
		size_t pos1;
		while (srcFilePointer.good())
		{
			getline(srcFilePointer, line); // get line from file
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			pos = line.find(search); // search
			bool found = (std::find(foundList.begin(), foundList.end(), file) != foundList.end());
			if (pos != string::npos && found == 0) // string::npos is returned if string is not found
			{
				//cout << "Found!" << endl;
				nrCuv++;
				//cout << "fisierul in care a fost gasit cuvantul este: " << file << endl;
				foundList.push_back(file);
				hstFilePointer.open("history.txt", std::ios::app);
				getline(hstFilePointer, line1); //get line from history
				pos1 = line1.find(search);
				//string search2 = search;
				if (pos1 != string::npos)
				{
					break;
				}
				else
				{
					hstFilePointer << search << endl;
				}
				hstFilePointer.close();
			}
				//break;
			
			else if (pos != string::npos && found == 1)
			{
				nrCuv++;
			}
			found1 = found;
		}
		if (found1 == 1)
		{
			//cout << "Numarul de cuvinte cheie gasite in " << file << " este: " << nrCuv << endl;

			fstream fndFilePointer;
			fndFilePointer.open(file);
			int word = 1;
			char ch;
			fndFilePointer.seekg(0, ios::end);
			int size = fndFilePointer.tellg();

			fndFilePointer.seekg(0, ios::beg);

			while (fndFilePointer)
			{
				fndFilePointer.get(ch);
				if (ch == ' ' || ch == 'n')
					word++;
			}

			foundKeyWords.insert(make_pair(nrCuv, word)); //contine perechi de nr cuv cheie gasite si nr cuv totale in acel fisier
			fndFilePointer.close();
			word = 0;
		}

		srcFilePointer.close();
		nrCuv = 0;
	}
	foundList.reverse();
}

void TxtFileManager::closeCfgFile()
{
	cfgFilePointer.close();
}

list<string> TxtFileManager::getListOfFiles()
{
	return listOfFiles;
}

void TxtFileManager::foundDensity()
{
	float density = 0;
	list<string>::iterator it = foundList.begin();
	map<int, int>::iterator it2;

	for (it2 = foundKeyWords.begin(); it2 != foundKeyWords.end(); it2++)
	{
		density = (float)it2->first / it2->second;
		fileDensity.insert(make_pair(density, *it));
		advance(it, 1);
	}
}

void TxtFileManager::bestRanking()
{
	list<string> aux;
	typedef pair<float, string> pair;

	//create an empty vector of pairs
	vector<pair> vec;

	//copy key-value pairs from map to the vector
	copy(fileDensity.begin(), fileDensity.end(), back_inserter<vector<pair>>(vec));

	//sort the vector by increasig in order of it's pair first value
	sort(vec.begin(), vec.end(), [](const pair& l, const pair& r)
		{if (l.first != r.first)
		return l.first > r.first; });

	//print the vector
	for (auto const& pair : vec)
	{
		//cout << pair.first << ", " << pair.second << endl;
		aux.push_back(pair.second);
	}

	//extract the filename
	for (auto top : aux)
	{
		const size_t last_slash_idx = top.find_last_of("\\/");
		if (std::string::npos != last_slash_idx)
		{
			top.erase(0, last_slash_idx + 1);
			//cout << "The filename is:     " << top << endl;
			top5.push_back(top);
		}
	}

	cout << "Top 5 fisiere: " << endl;
	int count = 1;
	for (auto top : this->top5)
	{
		cout << count << "). " << top << endl;
		count++;
	}
}

void TxtFileManager::upload()
{
}

void TxtFileManager::download()
{
}


