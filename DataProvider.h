#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Supermarket.h"

using namespace std;

constexpr char workersDBPath[] = "./WorkersDataBase.txt";
constexpr char clientsDBPath[] = "./ClientsDataBase.txt";
constexpr char salesDBPath[] = "./SalesDataBase.txt";
constexpr char productsDBPath[] = "./ProductsDataBase.txt";

class DataProvider{
private:
	Supermarket* supermarket;

	static int currentIDWorker;
	static int currentIDClient;
	static int currentIDSale;


public:
	void loadData();
	void setSupermarket(Supermarket* assignedSupermarket);


	static void getCurrentIdentifier();
};

