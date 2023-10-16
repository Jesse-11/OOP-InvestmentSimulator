#ifndef PRICEUPDATER_H
#define PRICEUPDATER_H

#include "Investment.h"

class PriceUpdater {
public:

    // Constructor
    PriceUpdater(Investment& investment);

    // Update the price of the investment (only once when called)
    void updatePriceOnce();

private:
    Investment& investment;
};

#endif // PRICEUPDATER_H