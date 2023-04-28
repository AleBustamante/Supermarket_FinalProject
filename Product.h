#pragma once
#include <string>

using namespace std;


class Product
{
protected:
	float costPrice;
	float sellPrice;
	float taxes;
	float displayPrice;
	int barcode;
	string name;

	//Manufacturer manufacturer

public:
	

	float getCostPrice();
	float getSellPrice();

	virtual void calculateTaxes() = 0;

};
