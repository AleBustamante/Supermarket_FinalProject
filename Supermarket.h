#pragma once
#include <vector>

#include "Product.h"
#include "Worker.h"
#include "Client.h"
#include "Sale.h"

using namespace std;


class Supermarket{
private:
	vector<Product*> products;
	vector<Worker*> workers;
	vector<Client*> clients;
	vector<Sale*> sales;

public:
	
};

