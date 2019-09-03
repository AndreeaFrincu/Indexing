#include "SearchEngine.h"

SearchEngine* SearchEngine::instance = nullptr;

Report SearchEngine::searchByContent(const list<string>& listOfFiles, const string& word)
{
	fstream srcFilePointer;
	string search;
	string line;//linie din fisierul in care caut
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
		while (srcFilePointer.good())
		{
			getline(srcFilePointer, line); // get line from file
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			pos = line.find(search); // search
			bool found = (std::find(mfoundList.begin(), mfoundList.end(), file) != mfoundList.end());
			if (pos != string::npos && found == 0) // string::npos is returned if string is not found
			{
				//cout << "Found!" << endl;
				nrCuv++;
				//cout << "fisierul in care a fost gasit cuvantul este: " << file << endl;
				mfoundList.push_back(file);
				bool found2 = (find(mlistForHistory.begin(), mlistForHistory.end(), search) != mlistForHistory.end());
				if (found2 == 0)
				{
					mlistForHistory.push_back(search);
				}
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

			mfoundKeyWords.insert(make_pair(nrCuv, word)); //contine perechi de nr cuv cheie gasite si nr cuv totale in acel fisier
			fndFilePointer.close();
			word = 0;
		}

		srcFilePointer.close();
		nrCuv = 0;
	}
	mfoundList.reverse();

	findDensity(mfoundList, mfoundKeyWords);

	return Report(search, mfileDensity);
}

void SearchEngine::findDensity(list<string> foundList, map<int, int> foundKeyWords)
{
	float density = 0;
	list<string>::iterator it = foundList.begin();
	map<int, int>::iterator it2;

	for (it2 = foundKeyWords.begin(); it2 != foundKeyWords.end(); it2++)
	{
		density = (float)it2->first / it2->second;
		mfileDensity.insert(make_pair(density, *it));
		advance(it, 1);
	}
}

void SearchEngine::showReport(Report rep)
{
	mtop5 = bestRanking();
	mtop5.reverse();
	map<float, string> dens = rep.getRepDensity();
	map<float, string>::iterator it;
	list<string>::iterator it2 = mtop5.begin();
	cout << "Pentru cuvantul " << rep.getRepWord() << " am gasit fisierele cu densitatile urmatoare: " << endl;

	for (it = dens.begin(); it != dens.end(); it++)
	{
		it->second = *it2;
		advance(it2, 1);
		cout << it->second << "\t" << it->first << endl;
	}
}

list<string> SearchEngine::getListForHistory()
{
	return this->mlistForHistory;
}

list<string> SearchEngine::bestRanking()
{
	list<string> aux;
	typedef pair<float, string> pair;

	//create an empty vector of pairs
	vector<pair> vec;

	//copy key-value pairs from map to the vector
	copy(mfileDensity.begin(), mfileDensity.end(), back_inserter<vector<pair>>(vec));

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
			mtop5.push_back(top);
		}
	}

	cout << "Top 5 fisiere: " << endl;
	int count = 1;
	for (auto top : this->mtop5)
	{
		if (count == 5)
			break;
		else
		{
			cout << count << "). " << top << endl;
			count++;
		}
	}

	return this->mtop5;
}
