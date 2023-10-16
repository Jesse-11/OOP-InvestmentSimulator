#include "PriceUpdater.h"
#include "Investment.h"

PriceUpdater::PriceUpdater(Investment& investment)
    : investment(investment) {}

void PriceUpdater::updatePriceOnce() {
    investment.updatePrice();
}