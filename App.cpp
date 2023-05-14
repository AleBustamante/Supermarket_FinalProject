#include "App.h"

void App::showLoginMenu(){
	int identifier;
	string password;
	cout << "INGRESE SU ID DE USUARIO: \n";
	cin >> identifier;
	cout << "INGRESE SU CONTRASENIA: \n";
	cin >> password;
	/*if (Credential::isPassCorrect(password)) {
		showSpecificMenu(supermarket.getWorkerOnID(identifier)->getCredential().getWorkerType());
	}*/

}

void App::showSpecificMenu(const WorkerType& workerType){
	switch (workerType)
	{
	case unasigned:
		cout << "El trabajador no cuenta con ninguna funcion asignada hasta el momento\n";
		cout << "PRESIONE ENTER PARA CONTINUAR\n";
		cin;
		system("CLS");
		break;
	case cashier:
		showCashierMenu();
		break;
	case warehouse:
		showWarehouseMenu();
		break;
	case management:
		ShowManagementMenu();
		break;
	default:
		cout << "ERROR";
		break;
	}
}

void App::showCashierMenu(){
	cout << "***********SELECCIONE CLIENTE***********\n";
	searchPrintResults(supermarket.getClients());

}

void App::showWarehouseMenu(){

}

void App::ShowManagementMenu(){

}

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
	/*int option = -1;
	assignSupermarket();
	dataProvider.loadData();
	do
	{
		showMenu();
		cin >> option;
		switch (option)
		{
		case 1:
			
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
	*/
	assignSupermarket();
	dataProvider.loadData();
	showCashierMenu();
}
