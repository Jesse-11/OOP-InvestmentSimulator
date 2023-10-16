#include "UserInterface.h"
#include "Investment.h"
#include "PriceUpdater.h"
#include <iostream>
#include <vector>
#include <thread>

UserInterface::UserInterface(std::vector<Investment*>& investments)
    : investments(investments), selectedInvestment(nullptr), priceUpdater(nullptr) {}

UserInterface::~UserInterface() {
    if (priceUpdater && priceUpdaterThread.joinable()) {
        priceUpdaterThread.join();
        delete priceUpdater;
    }
}

void UserInterface::showMenu() {
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

void UserInterface::displayInvestments() const {
    std::cout << "Available Investments:\n";

    for (const Investment* investment : investments) {
        std::cout << investment->GetSymbol() << "\n";
    }
}

void UserInterface::viewCurrentPrice() {
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

Investment* UserInterface::getInvestmentBySymbol(const std::string& symbol) const {
    for (const Investment* investment : investments) {
        if (investment->GetSymbol() == symbol) {
            return investment->clone();
        }
    }
    return nullptr;
}
