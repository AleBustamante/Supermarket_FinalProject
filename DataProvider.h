#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Supermarket.h"

using namespace std;

constexpr char workersDBPath[] = "./Data Bases/WorkersDataBase.txt";
constexpr char clientsDBPath[] = "./Data Bases/ClientsDataBase.txt";
constexpr char salesDBPath[] = "./Data Bases/SalesDataBase.txt";

class DataProvider{
private:
	Supermarket* supermarket;


public:
	void loadData();
};

