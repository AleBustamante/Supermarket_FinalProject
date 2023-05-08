#include "DataProvider.h"

void DataProvider::loadData(){
	//Read data from workersDB
	if (!filesystem::exists(workersDBPath)) {
		ofstream workersDB(workersDBPath);
		workersDB.close();
	}
	else {
		string name, lastName;
		float baseSalary, extraHours, discounts, discountForBenefits;
		int identifier;

		ifstream workersDB;
		workersDB.open(workersDBPath);
		workersDB.seekg(0, ios::beg);

		while (!workersDB.eof()) {
			workersDB >> identifier;
			workersDB >> name;
			workersDB >> lastName;
			workersDB >> baseSalary;
			workersDB >> extraHours;
			workersDB >> discounts;
			workersDB >> discountForBenefits;
			supermarket->workers.push_back(new Worker(name, lastName, baseSalary, identifier, extraHours, discounts, discountForBenefits));
		}		
		workersDB.close();
	}


	//Read data from clientsDB
	if (!filesystem::exists(clientsDBPath)) {
		ofstream clientsDB(clientsDBPath);
		clientsDB.close();
	}
	else {
		string name, lastName;
		int CIorNIT, identifier;

		ifstream clientsDB;
		clientsDB.open(clientsDBPath);
		clientsDB.seekg(0, ios::beg);
		
		while (!clientsDB.eof()) {
			clientsDB >> identifier;
			clientsDB >> name;
			clientsDB >> lastName;
			clientsDB >> CIorNIT;
			supermarket->clients.push_back(new Client(name, lastName, CIorNIT, identifier));
		}
		clientsDB.close();
	}


	//Read data from productsDB
	if (!filesystem::exists(productsDBPath)) {
		ofstream productsDB(productsDBPath);
		productsDB.close();
	}
	else {
		float costPrice, sellPrice, taxes, displayPrice;
		int barcode;
		string name;

		ifstream productsDB;
		productsDB.open(productsDBPath);
		productsDB.seekg(0, ios::beg);

		while (!productsDB.eof()) {
			productsDB >> barcode;
			productsDB >> name;
			productsDB >> costPrice;
			productsDB >> sellPrice;
			productsDB >> taxes;
			productsDB >> displayPrice;
			supermarket->products.push_back(new Product(barcode, costPrice, sellPrice, taxes, displayPrice, name));
		}
		productsDB.close();
	}

	//Read data from salesDB
	if (!filesystem::exists(salesDBPath)) {
		ofstream salesDB(salesDBPath);
		salesDB.close();
	}
	else {
		int identifier, IDWorker, IDClient, barcode;
		Date date;

		ifstream salesDB;
		salesDB.open(salesDBPath);
		salesDB.seekg(0, ios::beg);

		while (!salesDB.eof()) {
			salesDB >> identifier;
			salesDB >> IDWorker;
			salesDB >> IDClient;
			salesDB >> barcode;
			salesDB >> date.day;
			salesDB >> date.month;
			salesDB >> date.year;
			supermarket->sales.push_back(new Sale(supermarket->getProductOnBarcode(barcode), supermarket->getClientOnID(IDClient),
				supermarket->getWorkerOnID(IDWorker), date, identifier));
		}
		salesDB.close();
	}


}

void DataProvider::setSupermarket(Supermarket* assignedSupermarket){
	supermarket = assignedSupermarket;
}

void DataProvider::saveNewWorker(Worker* worker){

	ofstream workersDB;
	workersDB.open(workersDBPath, ios::app);
	workersDB << '\n';
	workersDB << worker->getIdentifier();
	workersDB << '\n';
	workersDB << worker->getName();
	workersDB << '\n';
	workersDB << worker->getLastName();
	workersDB << '\n';
	workersDB << worker->getBaseSalary();
	workersDB << '\n';
	workersDB << worker->getExtraHours();
	workersDB << '\n';
	workersDB << worker->getDiscounts();
	workersDB << '\n';
	workersDB << worker->getDiscountsForBenefits();
	workersDB << '\n';

	workersDB.close();
}

void DataProvider::saveNewClient(Client* client){

	ofstream clientDB;
	clientDB.open(clientsDBPath, ios::app);
	clientDB << '\n';
	clientDB << client->getIdentifier();
	clientDB << '\n';
	clientDB << client->getName();
	clientDB << '\n';
	clientDB << client->getLastName();
	clientDB << '\n';
	clientDB << client->getCIorNIT();

	clientDB.close();
}

void DataProvider::saveNewProduct(Product* product){
	ofstream productDB;
	productDB.open(productsDBPath, ios::app);
	productDB << '\n';
	productDB << product->getBarcode();
	productDB << '\n';
	productDB << product->getName();
	productDB << '\n';
	productDB << product->getCostPrice();
	productDB << '\n';
	productDB << product->getSellPrice();
	productDB << '\n';
	productDB << product->getTaxes();
	productDB << '\n';
	productDB << product->getDisplayPrice();

	productDB.close();
}

void DataProvider::saveNewSale(Sale* sale){

	ofstream saleDB;
	saleDB.open(salesDBPath, ios::app);
	saleDB << '\n';
	saleDB << sale->getIdetifier();
	saleDB << '\n';
	saleDB << sale->getCashier()->getIdentifier();
	saleDB << '\n';
	saleDB << sale->getClient()->getIdentifier();
	saleDB << '\n';
	saleDB << sale->getProduct()->getBarcode();
	saleDB << '\n';
	saleDB << sale->getDate().day;
	saleDB << '\n';
	saleDB << sale->getDate().month;
	saleDB << '\n';
	saleDB << sale->getDate().year;
	
	saleDB.close();
}


