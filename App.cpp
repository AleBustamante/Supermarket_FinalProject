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

	//Login screens
	print::printTitle("INICIAR SESION");
	print::printHints("Ingrese su identificador");
	print::setCursorToInputPos();
	cin >> triedID;
	logedWorker = supermarket.getWorkerOnID(triedID);
	if (logedWorker == nullptr) {
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
	if (!logedWorker->getCredential().isPassCorrect(triedPass)) {
		cout << "Error al ingresar la contraseña" << endl;
		return;
	}
	

	
	switch (logedWorker->getCredential().getWorkerType())
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
	int option;
	string input;
	Searchable* searchedClient = nullptr;
	Searchable* searchedProduct = nullptr;

	Client* selectedClient = nullptr;
	Product* selectedProduct = nullptr;
	do
	{
		system("CLS");
		print::printTitle("CAJERO");
		print::printHints("Ingrese una opcion y presione ENTER");
		print::setCursorToOutputPos();
		cout << "1. Registar nuevo cliente" << endl;
		cout << "2. Registrar venta" << endl;
		cout << "3. Guardar todos los cambios" << endl;
		cout << "0. Salir" << endl;
		print::setCursorToInputPos();
		cin >> input;
		option = stoi(input);
		switch (option)
		{
		case 1:
			system("CLS");
			registerNewClient();
			break;
		case 2:
			system("CLS");
			searchMenu(searchedClient, SearchType::client, "CAJERO", "ENTER para seleccionar al primer cliente de la lista");
			selectedClient = dynamic_cast<Client*> (searchedClient);
			selectedClient->addNewSale(new Sale(selectedClient, logedWorker, { 1, 1, 2023 }, 6));
			while (true) {
				system("CLS");
				searchMenu(searchedProduct, SearchType::product, "CAJERO", "ENTER para agregar el primer producto de la lista a la venta");
				selectedProduct = dynamic_cast<Product*> (searchedProduct);
				supermarket.sales.back()->addNewProduct(selectedProduct);
				system("CLS");
				print::printTitle("CAJERO");
				print::printHints("Presione q + ENTER para finalizar la compra", "Presione cualquer tecla + ENTER para continuar ingresando productos");
				print::setCursorToInputPos();
				cin >> input;
				if (input == "q") {
					system("CLS");
					print::printTitle("CAJERO");
					print::printHints("Presione cualquier tecla + ENTER para continuar");
					print::setCursorToInputPos();
					cout << "El total a pagar es de: " << supermarket.sales.back()->getTotalOfSale() << endl;
					cin >> input;
					break;
				}
				if (input == "q") {
					break;
				}
			}
		case 3:
			dataProvider.saveAllClients();
			dataProvider.saveAllSales();
			break;
		default:
			break;
		}

	} while (option != 0);
	
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
	
	int option;
	string input;
	Searchable* searchedProduct = nullptr;
	Product* selectedProduct = nullptr;
	Product newProduct;
	int barcode; float costPrice, sellPrice, taxes, displayPrice; string name; //New Product temp variables
	do
	{
		system("CLS");
		print::printTitle("ALMACEN");
		print::printHints("Ingrese una opcion y presione ENTER");
		print::setCursorToOutputPos();
		cout << "1. Registar nuevo producto" << endl;
		cout << "2. Eliminar producto" << endl;
		cout << "3. Mostrar todos los productos disponibles" << endl;
		cout << "4. Guardar todos los cambios" << endl;
		cout << "0. Salir" << endl;
		print::setCursorToInputPos();
		cin >> input;
		option = stoi(input);
		switch (option)
		{
		case 1:
			system("CLS");
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el nombre del producto");
			cin >> name;
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el código de barras del producto");
			print::setCursorToInputPos();
			cin >> barcode;
			system("CLS");
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el precio de costo");
			cin >> costPrice;
			system("CLS");
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el precio de venta");
			cin >> sellPrice;
			system("CLS");
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el total de impuestos");
			cin >> taxes;
			system("CLS");
			print::printTitle("ALMACEN");
			print::printHints("Ingrese el precio que se verá en el anaquel");
			cin >> displayPrice;
			supermarket.products.push_back(new Product(barcode, costPrice, sellPrice, taxes, displayPrice, name));
			break;
		case 2:
			system("CLS");
			searchMenu(searchedProduct, SearchType::product, "ALMACEN", "ENTER para eliminar el primer producto de la lista");
			selectedProduct = dynamic_cast<Product*> (searchedProduct);
			for (int i = 0; i < supermarket.products.size(); i++) {
				if (selectedProduct->getBarcode() == supermarket.products[i]->getBarcode()) {
					supermarket.products.erase(supermarket.products.begin() + i);
				}
			}
			break;
		case 3:
			print::printTitle("ALMACEN");
			print::printHints("Presione cualquier tecla + ENTER para continuar");
			print::setCursorToInputPos();
			supermarket.showAllProductsData();
			cin >> input;
			break;
		case 4:
			dataProvider.saveAllProducts();
			break;
		default:
			break;
		}
	}
	while (option != 0);

}

void App::ShowManagementMenu(){

	string input;
	int option;
	Searchable* searchedWorker = nullptr;
	Worker* selectedWorker = nullptr;

	Credential credential; int workerType; //new Credential variable
	int identifier; string name, lastName; float baseSalary; //new Worker temp variables
	do
	{
		system("CLS");
		print::printTitle("CAJERO");
		print::printHints("Ingrese una opcion y presione ENTER");
		print::setCursorToOutputPos();
		cout << "1. Registar nuevo trabajador" << endl;
		cout << "2. Eliminar trabajador de la nomina" << endl;
		cout << "3. Mostrar todos los trabajadores" << endl;
		cout << "4. Guardar todos los cambios" << endl;
		cout << "0. Salir" << endl;
		print::setCursorToInputPos();
		cin >> input;
		option = stoi(input);
		switch (option)
		{
		case 1:

			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese el tipo de trabajador a registrar");
			print::setCursorToOutputPos();
			cout << "1. Cajero" << endl;
			cout << "2. Almacenes" << endl;
			cout << "3. Gerencia" << endl;
			print::setCursorToInputPos();
			cin >> workerType;
			credential.workerType = (WorkerType)workerType;
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese el nombre del trabajador a registrar");
			print::setCursorToInputPos();
			cin >> name;
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese el apellido del trabajador a registrar");
			print::setCursorToInputPos();
			cin >> lastName;
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese el sueldo base que tendra");
			print::setCursorToInputPos();
			cin >> baseSalary;
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese el id quen tendra su cuenta");
			print::setCursorToInputPos();
			cin >> identifier;
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Ingrese la constraseña que tendra su cuenta");
			print::setCursorToInputPos();
			cin >> credential.hashedPassword;
			supermarket.workers.push_back(new Worker(name, lastName, credential, baseSalary, identifier));
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Presione cualquier tecla + ENTER para continuar");
			print::setCursorToInputPos();
			cout << "El nuevo trabajador fue registrado de forma exitosa" << endl;
			cin >> input;
			break;
		case 2:
			system("CLS");
			searchMenu(searchedWorker, SearchType::worker, "GERENCIA", "ENTER para eliminar el primer trabajador de la lista");
			selectedWorker = dynamic_cast<Worker*> (searchedWorker);
			for (int i = 0; i < supermarket.workers.size(); i++) {
				if (selectedWorker->getIdentifier() == supermarket.workers[i]->getIdentifier()) {
					supermarket.workers.erase(supermarket.workers.begin() + i);
				}
			}
			break;
		case 3:
			system("CLS");
			print::printTitle("GERENCIA");
			print::printHints("Presione cualquier tecla + ENTER para continuar");
			print::setCursorToInputPos();
			supermarket.showAllWorkersData();
			cin >> input;
			break;
		case 4:
			dataProvider.saveAllWorkers();
			break;
		default:
			break;
		}

	} while (option != 0);

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

	
}
