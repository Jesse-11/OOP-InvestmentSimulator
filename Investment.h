#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
using namespace std;

class Investment {
public:

    // Destructor
    virtual ~Investment() {}

    // Display the investment information   
    virtual void displayInfo() const = 0;

    // Get the Symbol of the investment
    virtual string GetSymbol() const = 0;

    // Get the current price of the investment
    virtual void updatePrice() = 0;

    // Clone the investment
    virtual Investment* clone() const = 0;

};

#endif // INVESTMENT_H