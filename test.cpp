#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Forward declarations
class Investment;
class InvestmentMarket;
class Stock;
class DividendMixin;
class DividendStock;
class PriceUpdater;
class UserInterface;

// Abstract base class for different types of investments
class Investment {
public:
    virtual ~Investment() {}
    virtual void displayInfo() const = 0;
    virtual std::string GetSymbol() const = 0;
    virtual void updatePrice() = 0;
    virtual Investment* clone() const = 0;
};

// Interface for an investment market
class InvestmentMarket {
public:
    virtual ~InvestmentMarket() {}
    virtual void displayInvestments() const = 0;
    virtual Investment* getInvestmentBySymbol(const std::string& symbol) const = 0;
};

// Concrete class representing a stock investment
class Stock : public Investment {
public:
    Stock(const std::string& name, const std::string& symbol, const std::string& apiKey)
        : name(name), symbol(symbol), apiKey(apiKey), currentPrice(0.0), initialPrice(0.0) {}

    void displayInfo() const override {
        std::cout << "Stock: " << GetSymbol() << "\n"
                  << "Current Price: " << GetCurrentPrice() << "\n";
    }

    std::string GetSymbol() const override {
        return symbol;
    }

    double GetCurrentPrice() const {
        return currentPrice;
    }

    // update the price of the stock
    void updatePrice() override { 
    
        std::string apiUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + GetSymbol() + "&apikey=" + apiKey;

        CURL* curl; // curl object
        CURLcode res; // curl code

        // Initialize curl
        curl_global_init(CURL_GLOBAL_DEFAULT); // initialize curl
        curl = curl_easy_init(); // initialize curl easy

        if (curl) {

            // Set the URL for the API request
            curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

            // Write the response data to a string
            std::string responseData;
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

            // Perform the request
            res = curl_easy_perform(curl);

            // Parse JSON response
            if (res == CURLE_OK) {

                try {

                    // Parse JSON response
                    nlohmann::json jsonResponse = nlohmann::json::parse(responseData);
                    double newPrice;

                    // Check if the price is a string and attempt conversion
                    if (jsonResponse["Global Quote"]["05. price"].is_string()) {
                        newPrice = std::stod(jsonResponse["Global Quote"]["05. price"].get<std::string>());
                    } else {
                        newPrice = jsonResponse["Global Quote"]["05. price"];
                    }

                    // Update current price
                    currentPrice = newPrice;

                    // If initial price is not set, set it to current price
    
                    if (initialPrice == 0.0) {
                        initialPrice = currentPrice;
                    }

                } catch (const nlohmann::json::exception& e) {
                    std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
                }

            } else {
                std::cerr << "Failed to fetch data from Alpha Vantage\n";
            }

            // Clean up
            curl_easy_cleanup(curl);
        }

        // Cleanup curl
        curl_global_cleanup();
    }

    Investment* clone() const override {
        return new Stock(*this);
    }

private:

    // Static callback function for writing data from the API response
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

    std::string name;
    std::string symbol;
    std::string apiKey;
    double currentPrice;
    double initialPrice;
};

// Mixin class providing dividend-related functionality
class DividendMixin {
public:
    double calculateDividendYield(const Stock& stock) const {
        return stock.GetCurrentPrice() * 0.0175;
    }
};

// Concrete class representing a stock investment with dividend
class DividendStock : public Stock, public DividendMixin {
public:
    DividendStock(const std::string& name, const std::string& symbol, const std::string& apiKey)
        : Stock(name, symbol, apiKey) {}

    void displayInfo() const override {
        std::cout << "Stock: " << GetSymbol() << "\n"
                  << "Current Price: " << GetCurrentPrice() << "\n"
                  << "Dividend Yield ($): " << std::fixed << std::setprecision(2) << calculateDividendYield(*this) << "\n";
    }

    Investment* clone() const override {
        return new DividendStock(*this);
    }
};

// Class responsible for updating the price of an investment
class PriceUpdater {
public:
    PriceUpdater(Investment& investment)
        : investment(investment) {}

    void updatePriceOnce() {
        investment.updatePrice();
    }

private:
    Investment& investment;
};

// User interface class for interacting with investments
class UserInterface {
public:
    UserInterface(std::vector<Investment*>& investments)
        : investments(investments), selectedInvestment(nullptr), priceUpdater(nullptr) {}

    ~UserInterface() {
        if (priceUpdater && priceUpdaterThread.joinable()) {
            priceUpdaterThread.join();
            delete priceUpdater;
        }
    }

    void showMenu() {
        char choice;

        do {
            std::cout << "\nChoose an option:\n";
            std::cout << "1. View Investments\n";
            std::cout << "2. View Current Price\n";
            std::cout << "3. Exit\n";

            std::cin >> choice;

            switch (choice) {
                case '1':
                    displayInvestments();
                    break;

                case '2':
                    viewCurrentPrice();
                    break;

                case '3':
                    std::cout << "Exiting the program\n";
                    break;

                default:
                    std::cout << "Invalid choice, type number 1, 2, or 3. Try again.\n";
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));

        } while (choice != '3');
    }

    void displayInvestments() const {
        std::cout << "Available Investments:\n";

        for (const Investment* investment : investments) {
            std::cout << investment->GetSymbol() << "\n";
        }
    }

    void viewCurrentPrice() {
        if (priceUpdater) {
            std::cout << "A price update is already running for an investment. Do you want to stop it? (y/n): ";
            char stopChoice;
            std::cin >> stopChoice;

            if (stopChoice == 'y' || stopChoice == 'Y') {
                delete priceUpdater;
                priceUpdater = nullptr;
            } else {
                return;
            }
        }

        std::cout << "Enter the symbol of the investment to view its current price: ";
        std::string symbol;
        std::cin >> symbol;

        Investment* tempInvestment = getInvestmentBySymbol(symbol);

        if (tempInvestment) {
            priceUpdater = new PriceUpdater(*tempInvestment);
            priceUpdater->updatePriceOnce();
            tempInvestment->displayInfo();
            selectedInvestment = tempInvestment;
        } else {
            std::cout << "Invalid investment symbol\n";
        }
    }

private:
    Investment* getInvestmentBySymbol(const std::string& symbol) const {
        for (const Investment* investment : investments) {
            if (investment->GetSymbol() == symbol) {
                return investment->clone();
            }
        }
        return nullptr;
    }

    std::vector<Investment*>& investments;
    Investment* selectedInvestment;
    PriceUpdater* priceUpdater;
    std::thread priceUpdaterThread;
};

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


