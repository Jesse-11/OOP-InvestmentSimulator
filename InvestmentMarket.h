#include <iostream>
#include <string>
#include <vector>
#include "Investment.h"
using namespace std;

class InvestmentMarket
{

    public:

        void AddInvestment(Investment& investment); // Add an investment to the market
        void RemoveInvestment(Investment& investment); // Remove an investment from the market

        // Getters
        vector<Investment>& getAvaliableInvestments(){ return avaliableInvestments; } // Get all the investments in the market

    private:
        vector<Investment> avaliableInvestments; // All the investments in the market



};