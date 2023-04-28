#pragma once


#include "Product.h"


class Worker;
class Client;


struct Date{
	int day;
	int month;
	int year;
};

class Sale{
private:
	Product* product;
	Date date;
	Client* client;
	Worker* cashier;
};

