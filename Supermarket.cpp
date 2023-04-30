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
