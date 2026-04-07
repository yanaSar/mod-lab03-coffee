// Copyright 2022 GHA Test Team

#include <iostream>
#include "../include/Automata.h"

int main() {
    Automata coffeeMachine;
    // 1. Попытка использовать автомат в выключенном состоянии
    std::cout << "=== ТЕСТ 1: Попытка использования выключенного автомата ==="
    << std::endl;
    coffeeMachine.getMenu();
    coffeeMachine.coin(50);
    coffeeMachine.choice(1);

    // 2. Включение автомата
    std::cout << "\n=== ТЕСТ 2: Включение автомата ===" << std::endl;
    coffeeMachine.on();

    // 3. Просмотр меню
    std::cout << "\n=== ТЕСТ 3: Просмотр меню ===" << std::endl;
    coffeeMachine.getMenu();

    // 4. Внесение денег
    std::cout << "\n=== ТЕСТ 4: Внесение денег ===" << std::endl;
    coffeeMachine.coin(100);

    // 5. Выбор напитка
    std::cout << "\n=== ТЕСТ 5: Выбор напитка (Coffee - №1) ===" << std::endl;
    coffeeMachine.choice(1);

    // 6. Покупка второго напитка с недостатком средств
    std::cout << "\n=== ТЕСТ 6: Покупка с недостатком средств ===" << std::endl;
    coffeeMachine.coin(20);
    coffeeMachine.choice(3);
    coffeeMachine.cancel();

    // 7. Успешная покупка после добавления денег
    std::cout << "\n=== ТЕСТ 7: Добавление денег и успешная покупка ==="
    << std::endl;
    coffeeMachine.coin(40);
    coffeeMachine.choice(3);

    // 8. Выключение автомата
    std::cout << "\n=== ТЕСТ 8: Выключение автомата ===" << std::endl;
    coffeeMachine.off();

    // 9. Попытка использования после выключения
    std::cout << "\n=== ТЕСТ 9: Попытка использования после выключения ==="
    << std::endl;
    coffeeMachine.coin(50);

    // 10. Повторное включение и быстрая покупка
    std::cout << "\n=== ТЕСТ 10: Повторное включение и покупка ==="
    << std::endl;
    coffeeMachine.on();
    coffeeMachine.coin(65);
    coffeeMachine.choice(7);

    // 11. Демонстрация отмены после выбора
    std::cout << "\n=== ТЕСТ 11: Отмена после выбора напитка ===" << std::endl;
    coffeeMachine.coin(55);
    coffeeMachine.choice(5);
    coffeeMachine.cancel();

    // 12. Выключение
    std::cout << "\n=== ТЕСТ 12: Финальное выключение ===" << std::endl;
    coffeeMachine.off();

    return 0;
}
