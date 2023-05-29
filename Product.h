#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Searchable.h"

using namespace std;


class Product : public Searchable{
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
	Product(const int& barcode, const string& name);

	int getBarcode();
	float getCostPrice();
	float getSellPrice();
	float getTaxes();
	float getDisplayPrice();
	string getName();

	void showAllProductData();


	//Searchable interface
	bool isInIdentifier(const int& search) override;
	bool isInName(const string& search) override;
	int searchedIdentifier() override;
	string searchedName() override;

};
