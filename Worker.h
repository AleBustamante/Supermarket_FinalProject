#pragma once
#include <iostream>
#include <string>
#include <sstream>


#include "Credential.h"
#include "Searchable.h"

using namespace std;


class Worker : public Searchable{
private:
	
	int identifier;

	Credential credential;

	string name;
	string lastName;
	float baseSalary;
	float extraHours;
	float discounts;
	float discountsForBenefits;
	



public:
	Worker(const string& name, const string& lastName, const Credential& credential, const float& baseSalary, const int& identifier = -1, const float& extraHours = 0.0f,
	const float& discounts = 0.0f, const float& discountsForBenefits = 0.0f);

	void showAllWorkerData();

	int getIdentifier();
	string getName();
	string getLastName();
	float getBaseSalary();
	float getExtraHours();
	float getDiscounts();
	float getDiscountsForBenefits();
	Credential getCredential();


	//Searchable interface
	bool isInIdentifier(const int& search) override;
	bool isInName(const string& search) override;
	int searchedIdentifier() override;
	string searchedName() override;

};

