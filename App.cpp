#include "App.h"

void App::showMenu(){
	cout << "Menu\n";
}

void App::assignSupermarket(){
	dataProvider.setSupermarket(&supermarket);
}

void App::run(){

	assignSupermarket();
	showMenu();
	dataProvider.loadData();

	supermarket.showAllWorkersData();

}
