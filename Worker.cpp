#include "Worker.h"



Worker::Worker(const string& name, const string& lastName, const float& baseSalary, const int& identifier,
			   const float& extraHours, const float& discounts, const float& discountsForBenefits){

	this->name = name;
	this->lastName = lastName;
	this->baseSalary = baseSalary;
	this->identifier = identifier;
	this->extraHours = extraHours;
	this->discounts = discounts;
	this->discountsForBenefits = discountsForBenefits;
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

