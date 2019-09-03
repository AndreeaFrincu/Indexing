#pragma once
#include <string>
#include <map>

class Report
{
	std::string mword;
	std::map<float, std::string> mfileDensity;
public:
	Report(const std::string& word, const std::map<float, std::string>& fileDensity);
	std::string getRepWord();
	std::map<float, std::string> getRepDensity();
};

