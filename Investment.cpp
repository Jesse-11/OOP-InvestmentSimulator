#include "Investment.h"
#include <iostream>
#include <string>

using namespace std;

double Investment::CalculateCurrentPrice() const
{
    return quantity * currentPrice; // return the current price of the investment
}

double Investment::CalculateProfitLoss() const
{
    return quantity * (currentPrice - purchasePrice); // return the profit or loss of the investment
}

void Investment::UpdatePrice(double newPrice)
{
    currentPrice = newPrice; // update the current price of the investment
}
