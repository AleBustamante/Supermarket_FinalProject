#include "Sale.h"
#include "Worker.h"
#include "Client.h"

Sale::Sale(Product* product, Client* client, Worker* cashier, const Date& date, const int& identifier){
	this->product = product;
	this->client = client;
	this->cashier = cashier;
	this->date = date;
	this->identifier = identifier;
}

void Sale::showAllSaleData(){
	cout << "CODIGO DE BARRAS DEL PRODUCTO: " << product->getBarcode() << endl;
	cout << "CODIGO DEL CLIENT: " << client->getIdentifier() << endl;
	cout << "CODIGO DEL CAJERO: " << cashier->getIdentifier() << endl;
	cout << "LA FECHA DE LA COMPRA FUE: " << date.day << '/' << date.month << '/' << date.year << endl << endl;
}
