#include "PacString.h"
#include <utility>
#include <stdio.h>

PacString::PacString()
{
}

PacString::PacString(const char *pszString)
{
	int size = (int) strlen(pszString) + 1;

	mpszData = new char[size];
	
	for (int i = 0; i < size; i++)
	{
		mpszData[i] = pszString[i];
	}
}

PacString::PacString(const PacString &rcData)
{
	PacString(rcData.mpszData);
}

PacString::~PacString()
{
	delete mpszData;
}

PacString& PacString::operator=(PacString rcData)
{
	using std::swap;

	swap(mpszData, rcData.mpszData);
	
	return *this;
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}
/*
PacString& PacString::operator+=(const PacString &rcData)
{
}
*/
PacString PacString::operator+(const PacString &rcData) const
{
	int totalSize = strlen(mpszData) + strlen(rcData.mpszData) + 1;
	int leftSize = strlen(mpszData);

	char * szConcat = new char[totalSize];

	for (int i = 0; i < leftSize; i++)
	{
		szConcat[i] = mpszData[i];
	}

	for (int i = 0; i < strlen(rcData.mpszData) + 1; i++)
	{
		szConcat[leftSize + i] = rcData.mpszData[i];
	}

	return PacString(szConcat);
}