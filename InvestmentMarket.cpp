#include "InvestmentMarket.h"
#include "Investment.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



void InvestmentMarket::AddInvestment(Investment& investment)
{
    avaliableInvestments.push_back(investment); // add new investment to end of the vector
}

void InvestmentMarket::RemoveInvestment(Investment& investment)
{
    // From the begin and end of the vector, use the inline function to compare the Investment and inv to find the investment to be removed
   auto it = remove_if(avaliableInvestments.begin(), avaliableInvestments.end(), [&investment](const Investment& inv) 
   {
        return inv.GetSymbol() == investment.GetSymbol(); // return the Symbol of the investment to be removed
   });
   avaliableInvestments.erase(it, avaliableInvestments.end()); // erase the investment from the vector 
}

