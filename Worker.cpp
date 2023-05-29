#include "Worker.h"



Worker::Worker(const string& name, const string& lastName, const Credential& credential, const float& baseSalary, const int& identifier,
			   const float& extraHours, const float& discounts, const float& discountsForBenefits){

	this->name = name;
	this->lastName = lastName;
	this->credential = credential;
	this->baseSalary = baseSalary;
	this->identifier = identifier;
	this->extraHours = extraHours;
	this->discounts = discounts;
	this->discountsForBenefits = discountsForBenefits;
}

Worker::Worker(const string& name, const string& lastName, const int& identifier)
{
	this->name = name;
	this->lastName = lastName;
	this->identifier = identifier;

}

void Worker::showAllWorkerData(){
	cout << "IDENTIFICADOR: " << identifier << endl;
	cout << "NOMBRE: " << name << endl;
	cout << "APELLIDO: " << lastName << endl;
	cout << "SALARIO: " << baseSalary << endl;
	cout << "HORAS EXTRA: " << extraHours << endl;
	cout << "DESCUENTOS: " << discounts << endl;
	cout << "DESCUENTOS POR BENEFICIOS: " << discountsForBenefits << endl << endl;
}



int Worker::getIdentifier(){	
	return identifier;
}

string Worker::getName(){
	return name;
}

string Worker::getLastName(){
	return lastName;
}

float Worker::getBaseSalary(){
	return baseSalary;
}

float Worker::getExtraHours(){
	return extraHours;
}

float Worker::getDiscounts(){
	return discounts;
}

float Worker::getDiscountsForBenefits(){
	return discountsForBenefits;
}

Credential Worker::getCredential(){
	return credential;
}

bool Worker::isInIdentifier(const int& search){
	string searchStr, identifierStr;
	stringstream searchBuff, identifierBuff;

	//Convert to stream
	searchBuff << search;
	identifierBuff << identifier;

	//Write on a string
	searchBuff >> searchStr;
	identifierBuff >> identifierStr;
	if (searchStr.size() > identifierStr.size()) {
		return false;
	}
	for (int i = 0; i < searchStr.size(); i++) {
		if (searchStr[i] != identifierStr[i]) {
			return false;
		}
	}
	return true;
}

bool Worker::isInName(const string& search){
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

int Worker::searchedIdentifier(){
	return identifier;
}

string Worker::searchedName(){
	return name + ' ' + lastName;
}
