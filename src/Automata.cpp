// Copyright 2022 GHA Test Team

#include "../include/Automata.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

Automata::Automata() : cash(0), state(STATES::OFF), selectedDrinkIndex(-1), 
menuSize(6) {
    std::string defaultMenu[] = {"Coffee", "Tea", 
        "Hot Chocolate", "Espresso", "Latte", "Cappuccino"};
    double defaultPrices[] = {50.0, 30.0, 60.0, 40.0, 55.0, 65.0};

    for (int i = 0; i < menuSize; i++) {
        menu[i] = defaultMenu[i];
        prices[i] = defaultPrices[i];
    }
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cash = 0;
        selectedDrinkIndex = -1;
        std::cout << "Automat ON. Wait coins..." << std::endl;
    } else {
        std::cout << "Automat already ON." << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        if (cash > 0) {
            std::cout << "Returning coins: " << cash << " rub." << std::endl;
            cash = 0;
        }
        state = STATES::OFF;
        std::cout << "Automat is OFF." << std::endl;
    } else if (state == STATES::OFF) {
        std::cout << "Automat already OFF." << std::endl;
    } else {
        std::cout << "Cannot turn off automat in current state." << std::endl;
    }
}

void Automata::coin(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid amount. Please insert a positive value." 
        << std::endl;
        return;
    }

    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        std::cout << "Coin inserted: " << amount << " rub. Current balance: " 
        << cash << " rub." << std::endl;
    } else {
        std::cout << "Cannot insert coin in current state." << std::endl;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < menuSize; i++) {
        std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] 
        << " rub." << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int drinkIndex) {
    if (state != STATES::ACCEPT) {
        std::cout << "Invalid choice. Please select a number from 1 to " 
        << menuSize << "." << std::endl;
        return;
    }

    if (drinkIndex < 1 || drinkIndex > menuSize) {
        std::cout << "Invalid choice. Please select a number from 1 to " 
        << menuSize << "." << std::endl;
        return;
    }

    selectedDrinkIndex = drinkIndex - 1;
    state = STATES::CHECK;
    std::cout << "You selected: " << menu[selectedDrinkIndex] 
    << ". Checking payment..." << std::endl;
    check();
}

bool Automata::check() {
    if (state != STATES::CHECK) {
        std::cout << "Cannot check payment in current state." << std::endl;
        return false;
    }

    if (selectedDrinkIndex == -1) {
        std::cout << "Cannot check payment. Drink not selected." << std::endl;
        state = STATES::WAIT;
        return false;
    }

    double price = prices[selectedDrinkIndex];
    if (cash >= price) {
        std::cout << "Payment successful. Preparing " 
        << menu[selectedDrinkIndex] << "..." << std::endl;
        cook();
        return true;
    } else {
        std::cout << "Insufficient funds. Please insert more money. " 
        << price - cash << " rub." << std::endl;
        state = STATES::WAIT;
        selectedDrinkIndex = -1;
        return false;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        if (cash > 0) {
            std::cout << "Canceling order. Returning coins: " 
            << cash << " rub." << std::endl;
            cash = 0;
        } else {
            std::cout << "Canceling order. No coins to return." << std::endl;
        }
        state = STATES::WAIT;
        selectedDrinkIndex = -1;
    } else {
        std::cout << "Cannot cancel order in current state." << std::endl;
    }
}

void Automata::cook() {
    if (state != STATES::CHECK) {
        std::cout << "Cannot start preparation in current state." << std::endl;
        return;
    }

    state = STATES::COOK;
    std::cout << "Preparing " << menu[selectedDrinkIndex] << "..." << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "   .";
        for (int j = 0; j < 100000000; j++) {}
    }
    std::cout << "Prepared!" << std::endl;
    finish();
}

void Automata::finish() {
    if (state != STATES::COOK) {
        std::cout << "Cannot finish preparation in current state." << std::endl;
        return;
    }

    double price = prices[selectedDrinkIndex];
    cash -= price;
    std::cout << "Your " << menu[selectedDrinkIndex] << " is ready!" << std::endl;

    if (cash > 0) {
        std::cout << "Returning change: " << cash << " rub." << std::endl;
        cash = 0;
    }

    state = STATES::WAIT;
    selectedDrinkIndex = -1;
}
