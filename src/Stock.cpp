#include "Stock.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

Stock::Stock(const std::string& name, const std::string& symbol, const std::string& apiKey)
    : name(name), symbol(symbol), apiKey(apiKey), currentPrice(0.0), initialPrice(0.0) {}

// Display the information of the stock
void Stock::displayInfo() const {
    std::cout << "Stock: " << GetSymbol() << "\n"
              << "Current Price: " << GetCurrentPrice() << "\n";
}

// Get the symbol of the stock
std::string Stock::GetSymbol() const {
    return symbol;
}

// Get the current price of the stock
double Stock::GetCurrentPrice() const {
    return currentPrice;
}

// update the price of the stock
void Stock::updatePrice() {

    // Construct the API URL
    std::string apiUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + GetSymbol() + "&apikey=" + apiKey;

    CURL* curl; // curl handle
    CURLcode res; // curl result

    curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize curl
    curl = curl_easy_init(); // Get curl handle

    if (curl) {

        // Set curl options
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        // Set callback function for writing data from the API response
        std::string responseData;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        // Perform the request
        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {

            try {

                // Parse the JSON response
                nlohmann::json jsonResponse = nlohmann::json::parse(responseData);
                double newPrice;

                // Check if the price is a string or a number
                if (jsonResponse["Global Quote"]["05. price"].is_string()) {
                    newPrice = std::stod(jsonResponse["Global Quote"]["05. price"].get<std::string>());

                // If the price is a number
                } else {
                    newPrice = jsonResponse["Global Quote"]["05. price"];
                }

                currentPrice = newPrice;

                if (initialPrice == 0.0) {
                    initialPrice = currentPrice;
                }

            // Catch any JSON parsing errors
            } catch (const nlohmann::json::exception& e) {
                std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
            }

        // If the request failed
        } else {
            std::cerr << "Failed to fetch data from Alpha Vantage\n";
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    // Clean up
    curl_global_cleanup();
}

// Static callback function for writing data from the API response
size_t Stock::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// clone the stock
Investment* Stock::clone() const {
    return new Stock(*this);
}