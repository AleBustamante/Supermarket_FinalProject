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
	int triedID;
	char bufferPass;
	string triedPass;
	Worker* worker;

	//Login screens
	print::printTitle("INICIAR SESION");
	print::printHints("Ingrese su identificador");
	print::setCursorToInputPos();
	cin >> triedID;
	worker = supermarket.getWorkerOnID(triedID);
	if (worker == nullptr) {
		cout << "Error al ingresar el identificador de usuario" << endl;
		return;
	}
	system("CLS");
	print::printTitle("INICIAR SESION");
	print::printHints("Ingrese su contrasenia");
	print::setCursorToInputPos();
	while (bufferPass = _getch()) {
		system("CLS");
		print::printTitle("INICIAR SESION");
		print::printHints("Ingrese su contrasenia");
		
		if (bufferPass == '\r') {
			system("CLS");
			break;
		}
		else if (bufferPass == '\b' && triedPass.size() == 0) {}

		else if (bufferPass == '\b') {
			triedPass.pop_back();
		}
		else {
			triedPass.push_back(bufferPass);
		}
		
		for (int i = 0; i < triedPass.size(); i++) {
			cout << "*";
		}

	}
	if (!worker->getCredential().isPassCorrect(triedPass)) {
		cout << "Error al ingresar la contraseña" << endl;
		return;
	}
	

	
	switch (worker->getCredential().getWorkerType())
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

void App::searchMenu(Searchable*& searchedObject, const SearchType& objectType, const string& title,
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
		case product:
			searchPrintResults(supermarket.getProducts(), input, search, searchedObject);
			break;
		case client:
			searchPrintResults(supermarket.getClients(), input, search, searchedObject);
			break;
		case worker:
			searchPrintResults(supermarket.getWorkers(), input, search, searchedObject);
			break;
		default:
			break;
		}	
	}
}

void App::showCashierMenu(){
	int input;
	Searchable* selectedClient = nullptr;
	Searchable* selectedProduct = nullptr;
	do
	{
		system("CLS");
		print::printTitle("CAJERO");
		print::printHints("Ingrese una opcion y presione ENTER");
		print::setCursorToOutputPos();
		cout << "1. Registar nuevo cliente" << endl;
		cout << "2. Registrar venta" << endl;
		print::setCursorToInputPos();
		cin >> input;
		switch (input)
		{
		case 1:
			system("CLS");
			registerNewClient();
			break;
		case 2:
			system("CLS");
			searchMenu(selectedClient, SearchType::client, "CAJERO", "ENTER para seleccionar al primer cliente de la lista");
			while (true) {
				searchMenu(selectedProduct, SearchType::product, "CAJERO", "ENTER para agregar el primer producto de la lista a la venta");
			}
			break;
		default:

			break;
		}

	} while (input != 0);
	
}

void App::registerNewClient() {
	string name, lastName, strCIorNIT;
	int CIorNIT;
	system("CLS");
	print::printTitle("REGISTRO NUEVO CLIENTE");
	print::printHints("Ingrese el nombre del client", "q + ENTER para salir");
	print::setCursorToInputPos();
	cin >> name;
	if (name == "q") { return; }
	system("CLS");
	print::printTitle("REGISTRO NUEVO CLIENTE");
	print::printHints("Ingrese el apellido del client", "q + ENTER para salir");
	print::setCursorToInputPos();
	cin >> lastName;
	if (lastName == "q") { return; }
	system("CLS");
	print::printTitle("REGISTRO NUEVO CLIENTE");
	print::printHints("Ingrese el CI o NIT del client", "q + ENTER para salir");
	print::setCursorToInputPos();
	cin >> strCIorNIT;
	if (strCIorNIT == "q") { return; }
	CIorNIT = stoi(strCIorNIT, nullptr, 10);
	supermarket.clients.push_back(new Client(name, lastName, CIorNIT));
}

void App::showWarehouseMenu(){
	Searchable* selectedProduct = nullptr;
	searchMenu(selectedProduct, SearchType::product, "ALMACEN", "ENTER para seleccionar el primer producto de la lista");
}

void App::ShowManagementMenu(){
	Searchable* selectedWorker = nullptr;
	searchMenu(selectedWorker, SearchType::worker, "GERENCIA", "ENTER para seleccionar al primer trabajador de la lista");
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

	showSpecificMenu(WorkerType::management);

	//ShowManagementMenu();
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
