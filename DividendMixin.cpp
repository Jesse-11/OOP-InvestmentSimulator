#include "DividendMixin.h"
#include "Stock.h"

double DividendMixin::calculateDividendYield(const Stock& stock) const {
    return stock.GetCurrentPrice() * 0.0175;
}