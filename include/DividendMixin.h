#ifndef DIVIDENDMIXIN_H
#define DIVIDENDMIXIN_H

class Stock;

class DividendMixin {
public:

    // Calculate the dividend yield of a stock based on yearly average return
    double calculateDividendYield(const Stock& stock) const;
};

#endif // DIVIDENDMIXIN_H