#include "PacString.h"
#include <utility>
#include <stdio.h>
#include <iostream>

PacString::PacString()
{
	std::cout << "CREATE()\n";
}

PacString::PacString(const char *pszString)
{
	std::cout << "CREATE(STRING)\n";
	int size = (int) strlen(pszString) + 1;

	mpszData = new char[size];
	
	for (int i = 0; i < size; i++)
	{
		mpszData[i] = pszString[i];
	}
}

PacString::PacString(const PacString &rcData)
{
	std::cout << "CREATE(PAC)\n";
	PacString(rcData.mpszData);
}

PacString::~PacString()
{
	std::cout << "DESTROY\n";
	delete mpszData;
}

PacString& PacString::operator=(PacString rcData)
{
	std::cout << "operator= \n";
	using std::swap;

	swap(mpszData, rcData.mpszData);
	
	return *this;
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	std::cout << "operator<< \n";
	out << rcData.mpszData;

	return out;
}

PacString& PacString::operator+=(const PacString &rcData)
{
	std::cout << "operator+= \n";
	*this = *this + rcData;
	return *this;
}

PacString PacString::operator+(const PacString &rcData) const
{
	std::cout << "operator+ \n";
	int totalSize = strlen(mpszData) + strlen(rcData.mpszData) + 1;
	int leftSize = strlen(mpszData);

	//const char * szConcatConst;
	char * szConcat = new char[totalSize];

	for (int i = 0; i < leftSize; i++)
	{
		szConcat[i] = mpszData[i];
	}

	for (int i = 0; i < strlen(rcData.mpszData) + 1; i++)
	{
		szConcat[leftSize + i] = rcData.mpszData[i];
	}

	//szConcatConst = szConcat;
	//delete szConcat;

	return PacString(szConcat); //szConcatConst
}