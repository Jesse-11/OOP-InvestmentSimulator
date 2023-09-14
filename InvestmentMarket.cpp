#include "InvestmentMarket.h"
#include "Investment.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



void InvestmentMarket::AddInvestment(Investment& investment)
{
    avaliableInvestments.push_back(investment);
}

void InvestmentMarket::RemoveInvestment(Investment& investment)
{
   auto it = remove_if(avaliableInvestments.begin(), avaliableInvestments.end(), [&investment](const Investment& inv) 
   {
        return inv.GetSymbol() == investment.GetSymbol();
   });
   avaliableInvestments.erase(it, avaliableInvestments.end());
}

