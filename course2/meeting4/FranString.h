#pragma once
#include <string>
#include <memory>

class FranString
{
	std::unique_ptr<char[]> internalString;
	int currentLength;
	
public:
	FranString();
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
	char* data() const;
	int length() const;
	~FranString();

private:
	
};



