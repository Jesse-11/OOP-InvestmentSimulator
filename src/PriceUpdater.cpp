#include "PriceUpdater.h"
#include "Investment.h"

PriceUpdater::PriceUpdater(Investment& investment)
    : investment(investment) {}

// Update the price of the investment (only once when called)
void PriceUpdater::updatePriceOnce() {
    investment.updatePrice();
}