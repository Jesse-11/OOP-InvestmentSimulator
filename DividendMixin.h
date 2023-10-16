#ifndef DIVIDENDMIXIN_H
#define DIVIDENDMIXIN_H

class Stock;

class DividendMixin {
public:
    double calculateDividendYield(const Stock& stock) const;
};

#endif // DIVIDENDMIXIN_H