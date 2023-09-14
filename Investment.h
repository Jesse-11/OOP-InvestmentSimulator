#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
#include <string>

using namespace std;

class Investment
{
    public:
        Investment(const string& name, const string& symbol, int quantity, double purchasePrice, double currentPrice, const string& dateOfPurchase, const string& owner)
        : name(name), symbol(symbol), quantity(quantity), purchasePrice(purchasePrice), currentPrice(currentPrice), dateOfPurchase(dateOfPurchase), owner(owner) {}

        double CalculateCurrentPrice() const; // returns the current price of the investment
        double CalculateProfitLoss() const; // returns the profit/loss of the investment
        void UpdatePrice(double newPrice); // updates the current price of the investment to match updated price

        // Getters
        string GetName() const { return name; }
        string GetSymbol() const { return symbol; }
        int GetQuantity() const { return quantity; }
        double GetPurchasePrice() const { return purchasePrice; }
        double GetCurrentPrice() const { return currentPrice; }
        string GetDateOfPurchase() const { return dateOfPurchase; }
        string GetOwner() const { return owner; }


    private:
        string name; // name of the investment (APPLE, GOOGLE, etc.)
        string symbol; // symbol of the investment (AAPL, GOOG, etc.)
        int quantity; // number of shares 
        double purchasePrice; // price of the investment when it was purchased
        double currentPrice; // current price of the investment
        string dateOfPurchase; // date of purchase _(Implemnt time of purchase)_
        string owner; // owner of the investment
};

#endif