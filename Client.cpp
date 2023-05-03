#include "Client.h"

Client::Client(const string& name, const string& lastName, const int& CIorNIT, const int& identifier){
	this->name = name;
	this->lastName = lastName;
	this->CIorNIT = CIorNIT;
	this->identifier = identifier;
	shoppingHistory.push_back(nullptr);
}

int Client::getIdentifier(){
	return identifier;
}

void Client::showAllClientData(){
	cout << "IDENTIFICADOR: " << identifier << endl;
	cout << "NOMBRE: " << name << endl;
	cout << "APELLIDO: " << lastName << endl;
	cout << "CI O NIT: " << CIorNIT << endl << endl;
}
