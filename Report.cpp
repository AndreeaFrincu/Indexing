#include "Report.h"

Report::Report(const std::string& word, const std::map<float, std::string>& fileDensity)
{
	this->mword = word;
	this->mfileDensity = fileDensity;
}

std::string Report::getRepWord()
{
	return this->mword;
}

std::map<float, std::string> Report::getRepDensity()
{
	return this->mfileDensity;
}
