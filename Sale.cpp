#include "Sale.h"
#include "Worker.h"
#include "Client.h"

Sale::Sale(vector<Product*> products, Client* client, Worker* cashier, const Date& date, const int& identifier){
	this->products = products;
	this->client = client;
	this->cashier = cashier;
	this->date = date;
	this->identifier = identifier;
}

void Sale::showAllSaleData(){
	cout << "CODIGO DEL CLIENT: " << client->getIdentifier() << endl;
	cout << "CODIGO DEL CAJERO: " << cashier->getIdentifier() << endl;
	cout << "LA FECHA DE LA COMPRA FUE: " << date.day << '/' << date.month << '/' << date.year << endl;
	cout << "PRODUCTOS COMPRADOS: \n";
	for (Product* p : products) {
		cout << p->getName() << '\n';
	}
	cout << endl;
}

int Sale::getIdetifier(){
	return identifier;
}

Date Sale::getDate(){
	return date;
}

vector<Product*> Sale::getProducts(){
	return products;
}



Client* Sale::getClient(){
	return client;
}

Worker* Sale::getCashier(){
	return cashier;
}
