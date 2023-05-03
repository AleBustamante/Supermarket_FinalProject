#pragma once
#include <vector>

#include "Product.h"
#include "Worker.h"
#include "Client.h"
#include "Sale.h"

using namespace std;


class Supermarket{
public:
	vector<Product*> products;
	vector<Worker*> workers;
	vector<Client*> clients;
	vector<Sale*> sales;

public:

	~Supermarket();

	vector<Product*> getProducts();
	vector<Worker*> getWorkers();
	vector<Client*> getClients();
	vector<Sale*> GetSales();

	void showAllWorkersData();
	void showAllClientsData();
	void showAllProductsData();
	void showAllSalesData();

	Product* getProductOnBarcode(const int& barcode);
	Client* getClientOnID(const int& identifier);
	Worker* getWorkerOnID(const int& identifier);
	
};

