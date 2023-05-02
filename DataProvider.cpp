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
		ifstream clientsDB;
		clientsDB.open(clientsDBPath);
		clientsDB.seekg(0, ios::beg);
		/*
		string name;
		string lastName;
		int CIorNIT;
		vector<Sale*> shoppingHistory;
		*/
		clientsDB.close();
	}


	//Read data from salesDB
	if (!filesystem::exists(salesDBPath)) {
		ofstream salesDB(salesDBPath);
		salesDB.close();
	}
	else {
		ifstream salesDB;
		salesDB.open(salesDBPath);
		salesDB.seekg(0, ios::beg);

		Product* product;
		Date date;
		Client* client;
		Worker* cashier;

		salesDB.close();
	}


}

void DataProvider::setSupermarket(Supermarket* assignedSupermarket){
	supermarket = assignedSupermarket;
}


