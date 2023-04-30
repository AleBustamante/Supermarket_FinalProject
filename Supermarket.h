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
	
};

