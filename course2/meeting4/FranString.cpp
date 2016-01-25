#include "stdafx.h"
#include "FranString.h"

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include <memory>

#include "string.h"

// Default Constructor
FranString::FranString()
{
	
}

FranString::FranString(const char *value)
{
	if (value)
	{
		currentLength = strlen(value) + 1;
		internalString = std::unique_ptr<char[]>( new char[currentLength] );
		memset(&internalString, 0, currentLength);
		memcpy(&internalString, value, strlen(value));
	}
}

// Copy Constructor
FranString::FranString(const FranString &strInstance)
{
	if (strInstance.internalString)
	{
		currentLength = strInstance.length() + 1;
		internalString = std::unique_ptr<char[]>( new char[currentLength] );
		
		memset(&internalString, 0, currentLength);
		memcpy(&internalString, strInstance.data(), currentLength);
	}
}

char * FranString::data() const
{
	if (this -> internalString)
	{
		return this -> internalString.get();
	}
	else
	{
		return NULL;
	}
}

/* empty() */
bool FranString::empty() const
{
	return currentLength - 1 > 0;
}

/* '=' operator */
FranString& FranString::operator=(const FranString &strInstance)
{
	if (strInstance.empty() == false)
	{
		currentLength = strInstance.length() + 1;
		internalString = std::unique_ptr<char[]>(new char[currentLength]);

		memset(&internalString, 0, currentLength);
		memcpy(&internalString, strInstance.data(), currentLength);
	}
	return *this;
}

/* '+' operator */
FranString& FranString::operator+(const FranString &strInstance)
{
	int newLength = currentLength + strInstance.length();

	std::unique_ptr<char[]> newString = std::unique_ptr<char[]>(new char[currentLength]);

	memset(&newString, 0, newLength);
	memcpy(&newString, &internalString, currentLength - 1);
	memcpy(&newString, strInstance.data(), strInstance.length());

	FranString *pStrResult = &FranString(newString.get());
	return *pStrResult;
}

FranString& FranString::operator+=(const FranString &strInstance)
{
	int newLength = currentLength + strInstance.length();

	std::unique_ptr<char[]> newString = std::unique_ptr<char[]>(new char[currentLength]);

	memset(&newString, 0, newLength);
	memcpy(&newString, &internalString, currentLength - 1);
	memcpy(&newString, strInstance.data(), strInstance.length());

	currentLength = newLength;
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
	return currentLength -1;
}

FranString::~FranString()
{
	
}
