#include "Worker.h"

Worker::Worker(const string& name, const string& lastName, const float& baseSalary){
	this->name = name;
	this->lastName = lastName;
	this->baseSalary = baseSalary;
	extraHours = 0.0f;
	discounts = 0.0f;
	discountForBenefits = 0.0f;
}
