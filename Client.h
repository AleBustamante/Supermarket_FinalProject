#pragma once
#include <string>
#include <vector>


#include "Sale.h"

using namespace std;


class Client{
private:
	int identifier;
	string name;
	string lastName;
	int CIorNIT;
	vector<Sale*> shoppingHistory;

public:

	Client(const string& name, const string& lastName, const int& CIorNIT, const int& identifier = -1);

	int getIdentifier();
	string getName();
	string getLastName();
	int getCIorNIT();

	void showAllClientData();
};

