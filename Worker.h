#pragma once
#include <iostream>
#include <string>

using namespace std;


class Worker{
private:
	
	int identifier;
	
	string name;
	string lastName;
	float baseSalary;
	float extraHours;
	float discounts;
	float discountsForBenefits;
	



public:
	Worker(const string& name, const string& lastName, const float& baseSalary, const int& identifier = -1, const float& extraHours = 0.0f,
	const float& discounts = 0.0f, const float& discountsForBenefits = 0.0f);

	void showAllWorkerData();

	int getIdentifier();
	string getName();
	string getLastName();
	float getBaseSalary();
	float getExtraHours();
	float getDiscounts();
	float getDiscountsForBenefits();
};

