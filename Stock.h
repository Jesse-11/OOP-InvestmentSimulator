#ifndef STOCK_H
#define STOCK_H

#include "Investment.h"
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

class Stock : public Investment {
public:

    Stock(const string& name, const string& symbol, const string& apiKey);

    // Display the information of the stock
    void displayInfo() const override;

    // Get the symbol of the stock
    string GetSymbol() const override;

    // Get the current price of the stock
    double GetCurrentPrice() const;

    // update the price of the stock
    void updatePrice() override;

    // clone the stock
    Investment* clone() const override;


private:

    // Static callback function for writing data from the API response
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output);

    string name;
    string symbol;
    string apiKey;
    double currentPrice;
    double initialPrice;

};

#endif // STOCK_H