#include "Product.h"

Product::Product(const int& barcode, const float& costPrice, const float& sellPrice, const float& taxes, 
                 float& displayPrice, const string& name){
    this->barcode = barcode;
    this->costPrice = costPrice;
    this->sellPrice = sellPrice;
    this->taxes = taxes;
    this->displayPrice = displayPrice;
    this->name = name;
}

int Product::getBarcode(){
    return barcode;
}
