#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "PriceUpdater.h"
#include <vector>
#include <thread>
using namespace std;

class Investment;

class UserInterface {
public:

    // Constructor
    UserInterface(vector<Investment*>& investments);

    // Destructor
    ~UserInterface();

    // Run the user interface showing the main menu
    void showMenu();

    // Display the investments in the market
    void displayInvestments() const;

    //View the current price of the selected investment
    void viewCurrentPrice();

private:
    
    // Get the investment from market by its symbol
    Investment* getInvestmentBySymbol(const string& symbol) const; 

    vector<Investment*>& investments;
    Investment* selectedInvestment;
    PriceUpdater* priceUpdater;
    thread priceUpdaterThread;
};


#endif // USERINTERFACE_H