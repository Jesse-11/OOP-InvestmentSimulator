#include "DividendStock.h"
#include <iostream>

DividendStock::DividendStock(const std::string& name, const std::string& symbol, const std::string& apiKey)
    : Stock(name, symbol, apiKey) {}

// Display the stock information
void DividendStock::displayInfo() const {
    std::cout << "Stock: " << GetSymbol() << "\n"
              << "Current Price: " << GetCurrentPrice() << "\n"
              << "Dividend Yield ($): " << std::fixed << std::setprecision(2) << calculateDividendYield(*this) << "\n";
}

// Clone the stock
Investment* DividendStock::clone() const {
    return new DividendStock(*this);
}