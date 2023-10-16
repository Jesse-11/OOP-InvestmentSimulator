#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>
using namespace std;

class Investment {
public:
    virtual ~Investment() {}   
    virtual void displayInfo() const = 0;
    virtual string GetSymbol() const = 0;
    virtual void updatePrice() = 0;
    virtual Investment* clone() const = 0;

};

#endif // INVESTMENT_H