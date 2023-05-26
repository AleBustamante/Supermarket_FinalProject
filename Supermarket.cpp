#include "Supermarket.h"

Supermarket::~Supermarket(){
    for(Product* p : products){
        delete p;
        p = nullptr;
    }
    for (Worker* w : workers) {
        delete w;
        w = nullptr;
    }
    for (Client* c : clients) {
        delete c;
        c = nullptr;
    }
    for (Sale* s : sales) {
        delete s;
        s = nullptr;
    }

}

vector<Product*> Supermarket::getProducts(){
    return products;
}

vector<Worker*> Supermarket::getWorkers(){
    return workers;
}

vector<Client*> Supermarket::getClients(){
    return clients;
}

vector<Sale*> Supermarket::GetSales(){
    return sales;
}

void Supermarket::showAllWorkersData(){
    for (Worker* w : workers) {
        w->showAllWorkerData();
    }
}

void Supermarket::showAllClientsData(){
    for (Client* c : clients) {
        c->showAllClientData();
    }
}

void Supermarket::showAllProductsData(){
    for (Product* p : products) {
        p->showAllProductData();
    }
} 

void Supermarket::showAllSalesData(){
    for (Sale* s : sales) {
        s->showAllSaleData();
    }
}

Product* Supermarket::getProductOnBarcode(const int& barcode){
    for (Product* p : products) {
        if (p->getBarcode() == barcode) {
            return p;
        }
    }
    return nullptr;
}

Client* Supermarket::getClientOnID(const int& identifier){
    for (Client* c : clients) {
        if (c->getCIorNIT() == identifier) {
            return c;
        }
    }
    return nullptr;
}

Worker* Supermarket::getWorkerOnID(const int& identifier){
    for (Worker* w : workers) {
        if (w->getIdentifier() == identifier) {
            return w;
        }
    }
    return nullptr;
}
