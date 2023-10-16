#ifndef DIVIDENDSTOCK_H
#define DIVIDENDSTOCK_H

#include "Stock.h"
#include "DividendMixin.h"
using namespace std;

class DividendStock : public Stock, public DividendMixin {
public:
    DividendStock(const string& name, const string& symbol, const string& apiKey);

    void displayInfo() const override;

    Investment* clone() const override;
};

#endif // DIVIDENDSTOCK_H