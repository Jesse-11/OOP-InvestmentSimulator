#include "Investment.h"
#include <iostream>
#include <string>

using namespace std;

double Investment::CalculateCurrentPrice() const
{
    return quantity * currentPrice;
}

double Investment::CalculateProfitLoss() const
{
    return quantity * (currentPrice - purchasePrice);
}

void Investment::UpdatePrice(double newPrice)
{
    currentPrice = newPrice;
}
