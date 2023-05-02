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

};

