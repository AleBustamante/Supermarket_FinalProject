#pragma once
#include <string>
#include <vector>
#include <list>
#include <sstream>

#include "Sale.h"
#include "Searchable.h"

using namespace std;


class Client : public Searchable{
private:
	int identifier;
	string name;
	string lastName;
	int CIorNIT;
	vector<Sale*> shoppingHistory;

public:

	Client(const string& name, const string& lastName, const int& CIorNIT, const int& identifier = -1);
	Client();

	int getIdentifier();
	string getName();
	string getLastName();
	int getCIorNIT();

	void showAllClientData();


	//Searchable interface
	bool isInIdentifier(const int& search) override;
	bool isInName(const string& search) override;
	int searchedIdentifier() override;
	string searchedName() override;
};

