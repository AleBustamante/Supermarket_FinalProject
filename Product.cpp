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

float Product::getCostPrice(){
    return costPrice;
}

float Product::getSellPrice(){
    return sellPrice;
}

float Product::getTaxes(){
    return taxes;
}

float Product::getDisplayPrice(){
    return displayPrice;
}

string Product::getName(){
    return name;
}

void Product::showAllProductData(){
    cout << "NOMBRE: " << name << endl;
    cout << "PRECIO DE COSTO: " << costPrice << "Bs." << endl;
    cout << "PRECIO DE VENTA: " << sellPrice << "Bs." << endl;
    cout << "IMPUESTOS: " << taxes << "Bs." << endl;
    cout << "PRECIO EN ANAQUEL: " << displayPrice << "Bs." << endl;
    cout << "CODIGO DE BARRAS: " << barcode << endl << endl;

}

bool Product::isInIdentifier(const int& search){
    string searchStr, barcodeStr;
    stringstream searchBuff, barcodeBuff;

    //Convert to stream
    searchBuff << search;
    barcodeBuff << barcode;

    //Write on a string
    searchBuff >> searchStr;
    barcodeBuff >> barcodeStr;
    if (searchStr.size() > searchStr.size()) {
        return false;
    }
    for (int i = 0; i < searchStr.size(); i++) {
        if (searchStr[i] != barcodeStr[i]) {
            return false;
        }
    }
    return true;
}

bool Product::isInName(const string& search){
    if (search.size() > name.size()) {
        return false;
    }
    else {
        for (int i = 0; i < search.size(); i++) {
            if (name[i] != search[i]) {
                return false;
            }
        }
        return true;
    }
}

int Product::searchedIdentifier(){
    return barcode;
}

string Product::searchedName(){
    return name;
}
