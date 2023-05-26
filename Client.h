#pragma once
#include <string>
#include <vector>
#include <list>
#include <sstream>

#include "Sale.h"
#include "Searchable.h"

using namespace std;

static int lastID = 0;

class Client : public Searchable{
private:
	string name;
	string lastName;
	int CIorNIT; //identifier
	vector<Sale*> shoppingHistory;

public:

	Client(const string& name, const string& lastName, const int& CIorNIT);
	Client();

	string getName();
	string getLastName();
	int getCIorNIT();

	void showAllClientData();

	void addNewSale(Sale* sale);

	int getAutoID();

	//Searchable interface
	bool isInIdentifier(const int& search) override;
	bool isInName(const string& search) override;
	int searchedIdentifier() override;
	string searchedName() override;
};

