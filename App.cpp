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
	int loginID;
	char loginPass;
	print::printTitle("INICIAR SESION");
	print::printHints("Ingrese su identificador");
	print::setCursorToInputPos();
	cin >> loginID;
	system("CLS");
	print::printTitle("INICIAR SESION");
	print::printHints("Ingrese su contrasenia");
	print::setCursorToInputPos();
	while (loginPass = _getch()) {
		cout << "*";
	}

	
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

void App::searchMenu(Searchable*& searchedObject, const WorkerType& objectType, const string& title,
	                 const string& hint1, const string& hint2, const string& hint3){
	char input;
	string search;
	print::printTitle(title);
	print::printHints(hint1, hint2, hint3);
	while (input = _getch()) {
		system("CLS");
		if (input == '\r' && searchedObject != nullptr) {
			cout << searchedObject->searchedName();
			return;
		}
		print::printTitle(title);
		print::printHints(hint1, hint2, hint3);
		switch (objectType)
		{
		case unasigned:
			break;
		case cashier:
			searchPrintResults(supermarket.getClients(), input, search, searchedObject);
			break;
		case warehouse:
			searchPrintResults(supermarket.getProducts(), input, search, searchedObject);
			break;
		case management:
			searchPrintResults(supermarket.getWorkers(), input, search, searchedObject);
			break;
		default:
			break;
		}	
	}
}

void App::showCashierMenu(){

	Searchable* selectedClient = nullptr;
	searchMenu(selectedClient, WorkerType::cashier, "CLIENTE", "ENTER para seleccionar al primer cliente de la lista");
}

void App::showWarehouseMenu(){
	Searchable* selectedProduct = nullptr;
	searchMenu(selectedProduct, WorkerType::warehouse, "PRODUCTOS", "ENTER para seleccionar el primer producto de la lista");
}

void App::ShowManagementMenu(){
	Searchable* selectedWorker = nullptr;
	searchMenu(selectedWorker, WorkerType::management, "TRABAJADORES", "ENTER para seleccionar al primer trabajador de la lista");
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
	assignSupermarket();
	dataProvider.loadData();
	print::setDefaultWindowSize();

	//showSpecificMenu(WorkerType::management);

	ShowManagementMenu();
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
	
}
