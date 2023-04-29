#include "DataProvider.h"

void DataProvider::loadData(){

	if (!filesystem::exists(workersDBPath)) {
		fstream newWorkersDB(workersDBPath);
	}
	if (!filesystem::exists(clientsDBPath)) {
		fstream newWorkersDB(clientsDBPath);
	}
	if (!filesystem::exists(salesDBPath)) {
		fstream newWorkersDB(salesDBPath);
	}


}
