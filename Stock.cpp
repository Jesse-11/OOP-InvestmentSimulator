#include "Stock.h"
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

Stock::Stock(const std::string& name, const std::string& symbol, const std::string& apiKey)
    : name(name), symbol(symbol), apiKey(apiKey), currentPrice(0.0), initialPrice(0.0) {}

void Stock::displayInfo() const {
    std::cout << "Stock: " << GetSymbol() << "\n"
              << "Current Price: " << GetCurrentPrice() << "\n";
}

std::string Stock::GetSymbol() const {
    return symbol;
}

double Stock::GetCurrentPrice() const {
    return currentPrice;
}

void Stock::updatePrice() {

    std::string apiUrl = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + GetSymbol() + "&apikey=" + apiKey;

    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        std::string responseData;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {

            try {

                nlohmann::json jsonResponse = nlohmann::json::parse(responseData);
                double newPrice;

                if (jsonResponse["Global Quote"]["05. price"].is_string()) {
                    newPrice = std::stod(jsonResponse["Global Quote"]["05. price"].get<std::string>());
                } else {
                    newPrice = jsonResponse["Global Quote"]["05. price"];
                }

                currentPrice = newPrice;

                if (initialPrice == 0.0) {
                    initialPrice = currentPrice;
                }

            } catch (const nlohmann::json::exception& e) {
                std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
            }

        } else {
            std::cerr << "Failed to fetch data from Alpha Vantage\n";
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

size_t Stock::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

Investment* Stock::clone() const {
    return new Stock(*this);
}