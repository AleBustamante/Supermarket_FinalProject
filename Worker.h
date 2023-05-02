#pragma once
#include <iostream>
#include <string>

using namespace std;


class Worker{
private:
	
	static int currentIdentifier;

	
	string name;
	string lastName;
	float baseSalary;
	float extraHours;
	float discounts;
	float discountsForBenefits;
	int identifier;



public:
	Worker(const string& name, const string& lastName, const float& baseSalary, const int& identifier = currentIdentifier, const float& extraHours = 0.0f,
	const float& discounts = 0.0f, const float& discountsForBenefits = 0.0f);

	void showAllWorkerData();
};

