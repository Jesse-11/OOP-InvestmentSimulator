#ifndef DIVIDENDSTOCK_H
#define DIVIDENDSTOCK_H

#include "Stock.h"
#include "DividendMixin.h"
using namespace std;

class DividendStock : public Stock, public DividendMixin {
public:

    // Constructor
    DividendStock(const string& name, const string& symbol, const string& apiKey);

    // Display the stock information
    void displayInfo() const override;

    // Clone the stock
    Investment* clone() const override;
};

#endif // DIVIDENDSTOCK_H