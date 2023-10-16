#ifndef INVESTMENTMARKET_H
#define INVESTMENTMARKET_H

#include <string>
using namespace std;

class Investment;

class InvestmentMarket {
public:

    // Destructor
    virtual ~InvestmentMarket() {}

    // Display the investments in the market
    virtual void displayInvestments() const = 0;

    // get the investment from market by its symbol
    virtual Investment* getInvestmentBySymbol(const string& symbol) const = 0;
};

#endif // INVESTMENTMARKET_H