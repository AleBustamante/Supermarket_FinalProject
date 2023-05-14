#pragma once
#include <string>

using namespace std;

class Searchable{
public:
	virtual bool isInIdentifier(const int& search) = 0;
	virtual bool isInName(const string& search) = 0;
	virtual int searchedIdentifier() = 0;
	virtual string searchedName() = 0;
};

