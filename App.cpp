#include "App.h"

void App::showMenu(){
	cout << "Menu\n";
}

void App::run(){

	showMenu();
	dataProvider.loadData();

}
