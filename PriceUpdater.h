#ifndef PRICEUPDATER_H
#define PRICEUPDATER_H

#include "Investment.h"

class PriceUpdater {
public:
    PriceUpdater(Investment& investment);

    void updatePriceOnce();

private:
    Investment& investment;
};

#endif // PRICEUPDATER_H