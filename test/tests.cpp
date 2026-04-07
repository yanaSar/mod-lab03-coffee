// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "../include/Automata.h"

// Тест 1: Проверка начального состояния
TEST(AutomataTest, InitialStateIsOff) {
    Automata vm;
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

// Тест 2: Проверка включения автомата
TEST(AutomataTest, TurnOnChangesStateToWait) {
    Automata vm;
    vm.on();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 3: Проверка выключения автомата
TEST(AutomataTest, TurnOffChangesStateToOff) {
    Automata vm;
    vm.on();
    vm.off();
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

// Тест 4: Проверка внесения денег
TEST(AutomataTest, CoinInsertionChangesStateToAccept) {
    Automata vm;
    vm.on();
    vm.coin(100.0);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

// Тест 5: Проверка выбора напитка без денег
TEST(AutomataTest, ChoiceWithoutMoneyStaysInWait) {
    Automata vm;
    vm.on();
    vm.choice(1);
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 6: Проверка успешной покупки
TEST(AutomataTest, SuccessfulPurchase) {
    Automata vm;
    vm.on();
    vm.coin(100.0);
    vm.choice(1);
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 7: Проверка недостаточности средств
TEST(AutomataTest, InsufficientFunds) {
    Automata vm;
    vm.on();
    vm.coin(30.0);
    vm.choice(1);
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 8: Проверка отмены операции
TEST(AutomataTest, CancelAfterCoinInsertion) {
    Automata vm;
    vm.on();
    vm.coin(100.0);
    vm.cancel();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 9: Проверка неверного выбора напитка
TEST(AutomataTest, InvalidDrinkChoice) {
    Automata vm;
    vm.on();
    vm.coin(100.0);
    vm.choice(99);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

// Тест 10: Проверка нескольких внесений денег
TEST(AutomataTest, MultipleCoinInsertions) {
    Automata vm;
    vm.on();
    vm.coin(50.0);
    vm.coin(30.0);
    vm.coin(20.0);
    EXPECT_EQ(vm.getState(), STATES::ACCEPT);
}

// Тест 11: Проверка отмены после выбора напитка
TEST(AutomataTest, CancelAfterChoice) {
    Automata vm;
    vm.on();
    vm.coin(100.0);
    vm.choice(1);
    vm.cancel();
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 12: Проверка покупки с точной суммой (без сдачи)
TEST(AutomataTest, PurchaseWithExactAmount) {
    Automata vm;
    vm.on();
    vm.coin(50.0);  // Точная сумма для кофе
    vm.choice(1);   // Coffee = 50 руб.
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 13: Проверка покупки разных напитков
TEST(AutomataTest, DifferentDrinksPurchase) {
    Automata vm;
    vm.on();

    // Покупаем чай
    vm.coin(30.0);
    vm.choice(2);  // Tea = 30 руб.
    EXPECT_EQ(vm.getState(), STATES::WAIT);

    // Покупаем горячий шоколад
    vm.coin(60.0);
    vm.choice(3);  // Hot Chocolate = 60 руб.
    EXPECT_EQ(vm.getState(), STATES::WAIT);

    // Покупаем эспрессо
    vm.coin(55.0);
    vm.choice(5);  // Espresso = 55 руб.
    EXPECT_EQ(vm.getState(), STATES::WAIT);
}

// Тест 14: Проверка невозможности внесения денег в выключенном состоянии
TEST(AutomataTest, CannotInsertCoinWhenOff) {
    Automata vm;
    vm.coin(100.0);
    EXPECT_EQ(vm.getState(), STATES::OFF);
}

// Тест 15: Проверка невозможности выбора напитка в выключенном состоянии
TEST(AutomataTest, CannotChooseWhenOff) {
    Automata vm;
    vm.choice(1);
    EXPECT_EQ(vm.getState(), STATES::OFF);
}
