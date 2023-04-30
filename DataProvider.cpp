#include "DataProvider.h"

void DataProvider::loadData(){

	if (!filesystem::exists(workersDBPath)) {
		ofstream workersDB(workersDBPath);
		workersDB.close();
	}
	else {
		fstream workersDB(workersDBPath, ios::app);
		workersDB.close();
	}


	if (!filesystem::exists(clientsDBPath)) {
		ofstream clientsDB(clientsDBPath);
		clientsDB.close();
	}
	if (!filesystem::exists(salesDBPath)) {
		ofstream salesDB(salesDBPath);
		salesDB.close();
	}


}
