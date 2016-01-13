#include "stdafx.h"
#include "FranString.h"

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>


#include "string.h"

// Default Constructor
FranString::FranString(void)
{
	
}

FranString::FranString(const char *pcValue)
{
	if (pcValue)
	{
		internalString = std::string(pcValue);
	}
}

// Copy Constructor
FranString::FranString(const FranString &strInstance)
{
	if (strInstance.internalString.empty() == false)
	{
		std::string newString = strInstance.internalString;
		internalString = newString;
	}
}

/* empty() */
bool FranString::empty() const
{
	return internalString.empty();
}

/* '=' operator */
FranString& FranString::operator=(const FranString &strInstance)
{
	if (strInstance.empty() == false)
	{
		internalString = strInstance.internalString;
	}
	return *this;
}

/* '+' operator */
FranString& FranString::operator+(const FranString &strInstance)
{
	std::string newString = internalString + strInstance.internalString;
	FranString *pStrResult = &FranString(newString.data());
	return *pStrResult;
}

FranString& FranString::operator+=(const FranString &strInstance)
{
	std::string newString = internalString + strInstance.internalString;
	internalString = newString;
	return *this;
}

bool operator==(const FranString &strLeft, const FranString &strRight)
{
	return strLeft.internalString == strRight.internalString;
}

bool operator!=(const FranString &strLeft, const FranString &strRight)
{ 
	return !operator==(strLeft, strRight); 
}


bool operator==(const FranString &strLeft, const char* &strRight)
{
	return strLeft.internalString == strRight;
}

bool operator!=(const FranString &strLeft, const char* &strRight)
{
	return !operator==(strLeft, strRight);
}

/* length() */
int FranString::length() const
{
	//std::cout << currentLength << std::endl;
	return internalString.length();
}

FranString::~FranString(void)
{
	
}
