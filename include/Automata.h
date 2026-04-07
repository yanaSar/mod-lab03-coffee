// Copyright 2022 GHA Test Team

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>

const int MAX_MENU_SIZE = 20;

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
        double cash;
        std::string menu[MAX_MENU_SIZE];
        double prices[MAX_MENU_SIZE];
        int menuSize;
        STATES state;
        int selectedDrinkIndex;
 public:
        Automata();
        void on();
        void off();
        void coin(double amount);
        void getMenu();
        STATES getState();
        void choice(int drinkIndex);
        bool check();
        void cancel();
        void cook();
        void finish();
};
#endif  // INCLUDE_AUTOMATA_H_
