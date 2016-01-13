#pragma once
#include <string>

class FranString
{
	std::string internalString;
	
public:
	FranString(void);
	FranString(const char*);
	FranString(const FranString&);
	FranString& FranString::operator=(const FranString &strInstance);
	FranString& FranString::operator+(const FranString &strInstance);
	FranString& FranString::operator+=(const FranString &strInstance);
	friend bool FranString::operator==(const FranString &strLeft, const FranString &strRight);
	friend bool FranString::operator!=(const FranString &strLeft, const FranString &strRight);

	friend bool FranString::operator==(const FranString &strLeft, const char* &strRight);
	friend bool FranString::operator!=(const FranString &strLeft, const char* &strRight);

	bool empty() const;
	int length() const;
	~FranString(void);
};

