#ifndef ASSET_H
#define ASSET_H

#include <iostream>
#include <string>
using namespace std;

class Asset {
public: 
    Asset(const string& name, const string& symbol, int quantity)
        : name(name), symbol(symbol), quantity(quantity) {}
    
    virtual ~Asset() {}

    virtual double getTotalValue() const = 0;

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Symbol: " << symbol << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: " << getTotalValue() << endl;
    }

protected:
    string name;
    string symbol;
    int quantity;
};


#endif