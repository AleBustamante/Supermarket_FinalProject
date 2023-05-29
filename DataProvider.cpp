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
		int identifier, wType;
		Credential credential;

		ifstream workersDB;
		workersDB.open(workersDBPath);
		workersDB.seekg(0, ios::beg);

		while (!workersDB.eof()) {
			workersDB >> identifier;
			workersDB >> credential.hashedPassword;
			workersDB >> wType;
			credential.workerType = (WorkerType)wType;
			workersDB >> credential.hasPriviliges;
			workersDB >> name;
			workersDB >> lastName;
			workersDB >> baseSalary;
			workersDB >> extraHours;
			workersDB >> discounts;
			workersDB >> discountForBenefits;
			supermarket->workers.push_back(new Worker(name, lastName, credential, baseSalary, identifier, extraHours, discounts, discountForBenefits));
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
			clientsDB >> name;
			clientsDB >> lastName;
			clientsDB >> CIorNIT;
			supermarket->clients.push_back(new Client(name, lastName, CIorNIT));
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
		int test = productsDB.tellg();
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
		vector<Product*> bufferProducts;

		ifstream salesDB;
		salesDB.open(salesDBPath);
		salesDB.seekg(0, ios::beg);

		while (!salesDB.eof()) {
			salesDB >> identifier;
			salesDB >> IDWorker; //CIorNIT
			salesDB >> IDClient;
			salesDB >> date.day;
			salesDB >> date.month;
			salesDB >> date.year;
			salesDB >> barcode;
			while (barcode != -111) {
				bufferProducts.push_back(supermarket->getProductOnBarcode(barcode));
				salesDB >> barcode;
			}
			supermarket->sales.push_back(new Sale(bufferProducts, supermarket->getClientOnID(IDClient),
											  supermarket->getWorkerOnID(IDWorker), date, identifier));
			bufferProducts.clear();
		}
		salesDB.close();
	}


}

void DataProvider::setSupermarket(Supermarket* assignedSupermarket){
	supermarket = assignedSupermarket;
}

void DataProvider::saveAllWorkers(){
	ofstream workersDB;
	workersDB.open(workersDBPath);
	int i = 1;
	for (Worker* w : supermarket->getWorkers()) {
		workersDB << w->getIdentifier();
		workersDB << '\n';
		workersDB << w->getCredential().getHashedPassword();
		workersDB << '\n';
		workersDB << w->getCredential().getWorkerType();
		workersDB << '\n';
		workersDB << w->getCredential().getHasPriviliges();
		workersDB << '\n';
		workersDB << w->getName();
		workersDB << '\n';
		workersDB << w->getLastName();
		workersDB << '\n';
		workersDB << w->getBaseSalary();
		workersDB << '\n';
		workersDB << w->getExtraHours();
		workersDB << '\n';
		workersDB << w->getDiscounts();
		workersDB << '\n';
		workersDB << w->getDiscountsForBenefits();
		if (i != supermarket->getWorkers().size()){
			workersDB << '\n';
		}
		else {

		}
		i++;
	}
}

void DataProvider::saveAllClients(){
	ofstream clientDB;
	clientDB.open(clientsDBPath);
	int i = 1;
	for (Client* c : supermarket->getClients()) {
		clientDB << c->getName();
		clientDB << '\n';
		clientDB << c->getLastName();
		clientDB << '\n';
		clientDB << c->getCIorNIT();
		if (i != supermarket->getClients().size()) {
			clientDB << '\n';
		}
		else {

		}
		i++;
	}
	clientDB.close();
}

void DataProvider::saveAllSales(){
	ofstream saleDB;
	saleDB.open(salesDBPath);
	int i = 1;
	for (Sale* s : supermarket->GetSales()) {
		saleDB << s->getIdetifier();
		saleDB << '\n';
		saleDB << s->getCashier()->getIdentifier();
		saleDB << '\n';
		saleDB << s->getClient()->getCIorNIT();
		saleDB << '\n';
		saleDB << s->getDate().day;
		saleDB << '\n';
		saleDB << s->getDate().month;
		saleDB << '\n';
		saleDB << s->getDate().year;
		saleDB << '\n';
		for (Product* p : s->getProducts()) {
			saleDB << p->getBarcode();
			saleDB << '\n';
		}
		saleDB << -111;
		if (i != supermarket->GetSales().size()) {
			saleDB << '\n';
		}
		else {

		}
		i++;
	}
	saleDB.close();

}

void DataProvider::saveAllProducts(){
	ofstream productDB;
	productDB.open(productsDBPath);
	int i = 1;
	for (Product* p : supermarket->getProducts()) {
		productDB << p->getBarcode();
		productDB << '\n';
		productDB << p->getName();
		productDB << '\n';
		productDB << p->getCostPrice();
		productDB << '\n';
		productDB << p->getSellPrice();
		productDB << '\n';
		productDB << p->getTaxes();
		productDB << '\n';
		productDB << p->getDisplayPrice();
		if (i != supermarket->getProducts().size()) {
			productDB << '\n';
		}
		else {

		}
		i++;

	}
	productDB.close();
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


	workersDB.close();
}

void DataProvider::saveNewClient(Client* client){

	ofstream clientDB;
	clientDB.open(clientsDBPath, ios::app);
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
	saleDB << sale->getDate().day;
	saleDB << '\n';
	saleDB << sale->getDate().month;
	saleDB << '\n';
	saleDB << sale->getDate().year;
	for (Product* p : sale->getProducts()) {
		saleDB << p->getBarcode();
		saleDB << '\n';
	}
	saleDB << -111;

	saleDB.close();
}


