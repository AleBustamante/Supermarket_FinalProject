#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Supermarket.h"

using namespace std;

constexpr char workersDBPath[] = "./WorkersDataBase.txt";
constexpr char clientsDBPath[] = "./ClientsDataBase.txt";
constexpr char salesDBPath[] = "./SalesDataBase.txt";

class DataProvider{
private:
	Supermarket* supermarket;


public:
	void loadData();
	void setSupermarket(Supermarket* assignedSupermarket);
};

