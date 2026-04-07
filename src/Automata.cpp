#include "../include/Automata.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

Automata::Automata() : cash(0), state(STATES::OFF), selectedDrinkIndex(-1), menuSize(7) {
    string defaultMenu[] = {"Coffee", "Tea", "Hot Chocolate", "Espresso", "Latte", "Cappuccino", "Mocha"};
    double defaultPrices[] = {50.0, 30.0, 60.0, 40.0, 55.0, 65.0, 65.0};

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
        cout << "Automat ON. Wait coins..." << std::endl;
    } else {
        cout << "Automat already ON." << std::endl;
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        if (cash > 0) {
            cout << "Returning coins: " << cash << " rub." << endl;
            cash = 0;
        }
        state = STATES::OFF;
        cout << "Automat is OFF." << endl;
    } else if (state == STATES::OFF) {
        cout << "Automat already OFF." << endl;
    } else {
        cout << "Cannot turn off automat in current state." << endl;
    }     
}

void Automata::coin(double amount) {
    if (amount <= 0) {
        cout << "Invalid amount. Please insert a positive value." << endl;
        return;
    }

    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += amount;
        state = STATES::ACCEPT;
        cout << "Coin inserted: " << amount << " rub. Current balance: " << cash << " rub." << endl;
    } else {
        cout << "Cannot insert coin in current state." << endl;
    }
}

void Automata::getMenu() {
    for (int i = 0; i < menuSize; i++) {
        cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " rub." << endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int drinkIndex) {
    if (state != STATES::ACCEPT) {
        cout << "Invalid choice. Please select a number from 1 to " << menuSize << "." << endl;
        return;
    }

    if (drinkIndex < 1 || drinkIndex > menuSize) {
        cout << "Invalid choice. Please select a number from 1 to " << menuSize << "." << endl;
        return;
    }

    selectedDrinkIndex = drinkIndex - 1;
    state = STATES::CHECK;
    cout << "You selected: " << menu[selectedDrinkIndex] << ". Checking payment..." << endl;
    check();
}

bool Automata::check() {
    if (state != STATES::CHECK) {
        cout << "Cannot check payment in current state." << endl;
        return false;
    }

    if(selectedDrinkIndex == -1) {
        cout << "Cannot check payment. Drink not selected." << endl;
        state = STATES::WAIT;
        return false;
    }

    double price = prices[selectedDrinkIndex];
    if (cash >= price) {
        cout << "Payment successful. Preparing " << menu[selectedDrinkIndex] << "..." << endl;
        cook();
        return true;
    } else {
        cout << "Insufficient funds. Please insert more money. " << price - cash << " rub." << endl;
        state = STATES::WAIT;
        selectedDrinkIndex = -1;
        return false;
    }
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        if (cash > 0) {
            cout << "Canceling order. Returning coins: " << cash << " rub." << endl;
            cash = 0;
        } else {
            cout << "Canceling order. No coins to return." << endl;
        }
        state = STATES::WAIT;
        selectedDrinkIndex = -1;
    } else {
        cout << "Cannot cancel order in current state." << endl;
    }
}

void Automata::cook() {
    if (state != STATES::CHECK) {
        cout << "Cannot start preparation in current state." << endl;
        return;
    }

    state = STATES::COOK;
    cout << "Preparing " << menu[selectedDrinkIndex] << "..." << endl;

    for(int i = 0; i < 3; i++) {
        cout << "   .";
        for (int j = 0; j < 100000000; j++);
    }
    cout << "Prepared!" << endl;
    finish();
}

void Automata::finish() {
    if (state != STATES::COOK) {
        cout << "Cannot finish preparation in current state." << endl;
        return;
    }

    double price = prices[selectedDrinkIndex];
    cash -= price;
    cout << "Your " << menu[selectedDrinkIndex] << " is ready!" << endl;

    if (cash > 0) {
        cout << "Returning change: " << cash << " rub." << endl;
        cash = 0;
    }

    state = STATES::WAIT;
    selectedDrinkIndex = -1;
}
