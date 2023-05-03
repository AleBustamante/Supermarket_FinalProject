#pragma once
#include <iostream>


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
	Product* product;
	Date date;
	Client* client;
	Worker* cashier;

public:
	Sale(Product* product, Client* client, Worker* cashier, const Date& date, const int& identifier);
	void showAllSaleData();


	int getIdetifier();
	Date getDate();
	Product* getProduct();
	Client* getClient();
	Worker* getCashier();
	
};

