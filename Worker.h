#pragma once
#include <iostream>
#include <string>

using namespace std;


class Worker{
private:
	string name;
	string lastName;
	float baseSalary;
	float extraHours;
	float discounts;
	float discountsForBenefits;


public:
	Worker(const string& name, const string& lastName, const float& baseSalary, const float& extraHours = 0.0f,
	const float& discounts = 0.0f, const float& discountsForBenefits = 0.0f);

	void showAllWorkerData();
};

