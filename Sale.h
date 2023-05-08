#pragma once
#include <iostream>
#include <vector>

#include "Product.h"


class Worker;
class Client;


using namespace std;

struct Date{
	int day;
	int month;
	int year;
};

class Sale{
private:
	int identifier;
	vector<Product*> products;
	Date date;
	Client* client;
	Worker* cashier;

public:
	Sale(vector<Product*> products, Client* client, Worker* cashier, const Date& date, const int& identifier);
	void showAllSaleData();


	int getIdetifier();
	Date getDate();
	vector<Product*> getProducts();
	Client* getClient();
	Worker* getCashier();
	
};

