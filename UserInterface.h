#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "PriceUpdater.h"
#include <vector>
#include <thread>
using namespace std;

class Investment;

class UserInterface {
public:
    UserInterface(vector<Investment*>& investments);
    ~UserInterface();

    void showMenu();
    void displayInvestments() const;
    void viewCurrentPrice();

private:
    Investment* getInvestmentBySymbol(const string& symbol) const; 

    vector<Investment*>& investments;
    Investment* selectedInvestment;
    PriceUpdater* priceUpdater;
    thread priceUpdaterThread;
};


#endif // USERINTERFACE_H