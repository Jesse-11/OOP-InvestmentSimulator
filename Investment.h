#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <string>
#include "Asset.h"

using namespace std;

class Investment : public Asset
{
public:
    Investment(const string& name, const string& symbol, int quantity, double purchasePrice,const string& purchaseDate)
    : Asset(name, symbol, quantity), purchaseDate(purchaseDate), purchasePrice(purchasePrice) {}

    double CalculateCurrentPrice() const; // returns the current price of the investment
    double CalculateProfitLoss() const; // returns the profit/loss of the investment
    void UpdatePrice(double newPrice); // updates the current price of the investment to match updated price

    // Getters
    string GetName() const { return name; }
    string GetSymbol() const { return symbol; }
    int GetQuantity() const { return quantity; }
    double GetPurchasePrice() const { return purchasePrice; }
    string GetPurchaseDate() const { return purchaseDate; }


protected:
    double purchasePrice; // price of the investment when it was purchased
    string purchaseDate; // date of purchase
};

#endif