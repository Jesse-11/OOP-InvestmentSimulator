#ifndef INVESTMENTMARKET_H
#define INVESTMENTMARKET_H

#include <string>
using namespace std;

class Investment;

class InvestmentMarket {
public:
    virtual ~InvestmentMarket() {}
    virtual void displayInvestments() const = 0;
    virtual Investment* getInvestmentBySymbol(const string& symbol) const = 0;
};

#endif // INVESTMENTMARKET_H