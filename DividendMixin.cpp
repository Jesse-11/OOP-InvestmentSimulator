#include "DividendMixin.h"
#include "Stock.h"

// Calculate the dividend yield of a stock based on yearly average return
double DividendMixin::calculateDividendYield(const Stock& stock) const {
    return stock.GetCurrentPrice() * 0.0175;
}