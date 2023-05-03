#pragma once
#include <iostream>
#include <Windows.h>

#include "Supermarket.h"
#include "DataProvider.h"

using namespace std;

class App{
private:
	Supermarket supermarket;
	DataProvider dataProvider;

	void showMenu();
	void assignSupermarket();

public:
	void run();
};

