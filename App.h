#pragma once
#include <iostream>

#include "Supermarket.h"

using namespace std;

class App{
private:
	Supermarket supermarket;

	void showMenu();
	

public:
	void run();
};

