#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Supermarket.h"
#include "DataProvider.h"
#include "Credential.h"
#include "Searchable.h"
#include "Search.h"


using namespace std;

class App{
private:
	Supermarket supermarket;
	DataProvider dataProvider;
	//Credential loginCredentials;

	void showLoginMenu();
	void showSpecificMenu(const WorkerType& workerType);

	void showCashierMenu();
	void showWarehouseMenu();
	void ShowManagementMenu();

	void showMenu();
	void assignSupermarket();



public:
	void run();
};

