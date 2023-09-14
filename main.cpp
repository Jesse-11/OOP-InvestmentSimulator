#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>

#include "Investment.cpp"
#include "InvestmentMarket.cpp"
using namespace std;

int main () {

    /*
    // Test Investment class
    Investment investment1("Apple", "AAPL", 10, 100.00, 120.00, "01/01/2021", "John Doe");
    Investment investment2("Google", "GOOG", 20, 200.00, 220.00, "01/01/2021", "John Doe");
    Investment investment3("Tesla", "TSLA", 30, 300.00, 320.00, "01/01/2021", "John Doe");

    vector<Investment> investments;
    investments.push_back(investment1);
    investments.push_back(investment2);
    investments.push_back(investment3);

    for (int i = 0; i < investments.size(); i++)
    {
        cout << investments[i].GetName() << endl;
        cout << investments[i].GetSymbol() << endl;
        cout << investments[i].GetQuantity() << endl;
        cout << investments[i].GetPurchasePrice() << endl;
        cout << investments[i].GetCurrentPrice() << endl;
        cout << investments[i].GetDateOfPurchase() << endl;
        cout << investments[i].GetOwner() << endl;
        cout << investments[i].CalculateCurrentPrice() << endl;
        cout << investments[i].CalculateProfitLoss() << endl;
        cout << endl;
    }
    */



   /*
   // Test InvestmentMarket class
    InvestmentMarket market;
    Investment investment1("Apple", "AAPL", 10, 100.00, 120.00, "01/01/2021", "John Doe");
    Investment investment2("Google", "GOOG", 20, 200.00, 220.00, "01/01/2021", "John Doe");
    Investment investment3("Tesla", "TSLA", 30, 300.00, 320.00, "01/01/2021", "John Doe");

    market.AddInvestment(investment1);
    market.AddInvestment(investment2);
    market.AddInvestment(investment3);

    vector<Investment> investments = market.getAvaliableInvestments();

    //code to display all investments
    for (int i = 0; i < investments.size(); i++)
    {
        cout << investments[i].GetName() << endl;
        cout << investments[i].GetSymbol() << endl;
        cout << investments[i].GetQuantity() << endl;
        cout << investments[i].GetPurchasePrice() << endl;
        cout << investments[i].GetCurrentPrice() << endl;
        cout << investments[i].GetDateOfPurchase() << endl;
        cout << investments[i].GetOwner() << endl;
        cout << investments[i].CalculateCurrentPrice() << endl;
        cout << investments[i].CalculateProfitLoss() << endl;
        cout << endl;
    }

    // code to remove an investment from the market
    market.RemoveInvestment(investment1);

    investments = market.getAvaliableInvestments();

    //code to display all investments
    for (int i = 0; i < investments.size(); i++)
    {
        cout << investments[i].GetName() << endl;
        cout << investments[i].GetSymbol() << endl;
        cout << investments[i].GetQuantity() << endl;
        cout << investments[i].GetPurchasePrice() << endl;
        cout << investments[i].GetCurrentPrice() << endl;
        cout << investments[i].GetDateOfPurchase() << endl;
        cout << investments[i].GetOwner() << endl;
        cout << investments[i].CalculateCurrentPrice() << endl;
        cout << investments[i].CalculateProfitLoss() << endl;
        cout << endl;
    }
    */



    return 0;
}