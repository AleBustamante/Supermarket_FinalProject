#include "App.h"

void App::showMenu(){
	cout << "***********MENU***********\n";
	cout << "1. Registrar nuevo trabajador\n";
	cout << "2. Registrar nuevo cliente\n";
	cout << "3. Registrar nuevo producto\n";
	cout << "4. Mostrar todos los trabajadores\n";
	cout << "5. Mostrar todos los clientes\n";
	cout << "6. Mostrar todos los productos\n";
	cout << "7. Mostrar todas las ventas\n";
	cout << "0. Salir\n";
	cout << "***************************\n";
}

void App::assignSupermarket(){
	dataProvider.setSupermarket(&supermarket);
}

void App::run(){
	int option = -1;
	assignSupermarket();
	dataProvider.loadData();
	Worker* c = new Worker("juan", "Perez", 4000, 2, 3, 0, 200);
	do
	{
		showMenu();
		cin >> option;
		switch (option)
		{
		case 1:
			
			dataProvider.saveNewWorker(c);
			delete c;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("CLS");
			supermarket.showAllWorkersData();
			break;
		case 5:
			system("CLS");
			supermarket.showAllClientsData();
			break;
		case 6:
			system("CLS");
			supermarket.showAllProductsData();
			break;
		case 7:
			system("CLS");
			supermarket.showAllSalesData();
			break;
		case 0:
			system("CLS");
			cout << "HASTA LUEGO";
			break;
		default:
			cout << "La opcion ingresado no es valida\n";
			system("CLS");
			break;
		}
	} while (option != 0);
	
}
