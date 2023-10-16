#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Investment.h"
#include "InvestmentMarket.h"
#include "Stock.h"
#include "DividendMixin.h"
#include "DividendStock.h"
#include "PriceUpdater.h"
#include "UserInterface.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>

int main() {
    // Replace "YOUR_API_KEY" with your Alpha Vantage API key
    std::string apiKey = "YOUR_API_KEY";

    // Create vector of investments automatically using a loop
    std::vector<Investment*> investments;

    // List of DividendStock data
    std::vector<std::tuple<std::string, std::string, std::string>> dividendStockData = {
        {"Microsoft Corporation", "MSFT", apiKey},
        {"Apple Inc.", "AAPL", apiKey},
        {"Amazon Inc.", "AMZN", apiKey},
        {"Facebook Inc.", "META", apiKey},
        {"Google LLC.", "GOOGL", apiKey}
    };

    // Create DividendStock instances and add them to the investments vector
    for (const auto& data : dividendStockData) {
        const std::string& name = std::get<0>(data);
        const std::string& symbol = std::get<1>(data);
        const std::string& stockApiKey = std::get<2>(data);

        DividendStock* dividendStock = new DividendStock(name, symbol, stockApiKey);
        investments.push_back(dividendStock);
    }

    // Create instance of UserInterface
    UserInterface userInterface(investments);

    // Show menu
    userInterface.showMenu();

    // Clean up
    for (Investment* investment : investments) {
        delete investment;
    }

    return 0;
}
