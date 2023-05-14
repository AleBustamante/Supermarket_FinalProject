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

string Client::getName(){
	return name;
}

string Client::getLastName(){
	return lastName;
}

int Client::getCIorNIT(){
	return CIorNIT;
}

void Client::showAllClientData(){
	cout << "IDENTIFICADOR: " << identifier << endl;
	cout << "NOMBRE: " << name << endl;
	cout << "APELLIDO: " << lastName << endl;
	cout << "CI O NIT: " << CIorNIT << endl << endl;
}

bool Client::isInIdentifier(const int& search){
	string searchStr, CIorNITStr;
	stringstream searchBuff, CIorNITBuff;
	
	//Convert to stream
	searchBuff << search;
	CIorNITBuff << CIorNIT;

	//Write on a string
	searchBuff >> searchStr;
	CIorNITBuff >> CIorNITStr;
	if (searchStr.size() > CIorNITStr.size()) {
		return false;
	}
	for (int i = 0; i < searchStr.size(); i++) {
		if (searchStr[i] != CIorNITStr[i]) {
			return false;
		}
	}
	return true;
}

bool Client::isInName(const string& search){
	string fullName = name + ' ' + lastName;
	if (search.size() > fullName.size()) {
		return false;
	}
	else {
		for (int i = 0; i < search.size(); i++) {
			if (fullName[i] != search[i]) {
				return false;
			}
		}
		return true;
	}
}

int Client::searchedIdentifier(){
	return CIorNIT;
}

string Client::searchedName(){
	return name + ' ' + lastName;
}

