#pragma once
#include <string>

using namespace std;


class Worker{
private:
	string name;
	string lastName;
	float baseSalary;
	float extraHours;
	float discounts;
	float discountForBenefits;


public:
	Worker(const string& name, const string& lastName, const float& baseSalary);

};

