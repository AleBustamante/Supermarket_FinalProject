#include "DataProvider.h"

void DataProvider::loadData(){

	if (!filesystem::exists(workersDBPath)) {
		ofstream workersDB(workersDBPath);
		workersDB.close();
	}
	else {
		ifstream workersDB;
		workersDB.open(workersDBPath);
		workersDB.seekg(0, ios::beg);

		string name = "", lastName = "";
		float baseSalary = 0, extraHours = 0, discounts = 0, discountForBenefits = 0;

		while (!workersDB.eof()) {

			workersDB >> name;
			workersDB >> lastName;
			workersDB >> baseSalary;
			workersDB >> extraHours;
			workersDB >> discounts;
			workersDB >> discountForBenefits;

			supermarket->workers.push_back(new Worker(name, lastName, baseSalary, extraHours, discounts, discountForBenefits));
		}

		
		workersDB.close();
	}


	if (!filesystem::exists(clientsDBPath)) {
		ofstream clientsDB(clientsDBPath);
		clientsDB.close();
	}
	else {
		fstream clientsDB(workersDBPath, ios::app);
		clientsDB.close();
	}


	if (!filesystem::exists(salesDBPath)) {
		ofstream salesDB(salesDBPath);
		salesDB.close();
	}
	else {
		fstream salesDB(workersDBPath, ios::app);
		salesDB.close();
	}


}

void DataProvider::setSupermarket(Supermarket* assignedSupermarket){
	supermarket = assignedSupermarket;
}


