#pragma once
#include <iostream>
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
	Product(const int& barcode, const float& costPrice, const float& sellPrice, const float& taxes, 
		    float& displayPrice, const string& name);


	int getBarcode();
	float getCostPrice();
	float getSellPrice();
	float getTaxes();
	float getDisplayPrice();
	string getName();

	void showAllProductData();

};
