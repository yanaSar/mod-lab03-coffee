// Copyright 2022 GHA Test Team

#include "../include/Automata.h"
#include <iostream>
using namespace std;

int main() {
    Automata coffeeMachine;
    // 1. Попытка использовать автомат в выключенном состоянии
    cout << "=== ТЕСТ 1: Попытка использования выключенного автомата ===" << endl;
    coffeeMachine.getMenu();
    coffeeMachine.coin(50);
    coffeeMachine.choice(1);
    
    // 2. Включение автомата
    cout << "\n=== ТЕСТ 2: Включение автомата ===" << endl;
    coffeeMachine.on();
    
    // 3. Просмотр меню
    cout << "\n=== ТЕСТ 3: Просмотр меню ===" << endl;
    coffeeMachine.getMenu();
    
    // 4. Внесение денег
    cout << "\n=== ТЕСТ 4: Внесение денег ===" << endl;
    coffeeMachine.coin(100);
    
    // 5. Выбор напитка
    cout << "\n=== ТЕСТ 5: Выбор напитка (Coffee - №1) ===" << endl;
    coffeeMachine.choice(1);
    
    // 6. Покупка второго напитка с недостатком средств
    cout << "\n=== ТЕСТ 6: Покупка с недостатком средств ===" << endl;
    coffeeMachine.coin(20);
    coffeeMachine.choice(3);
    coffeeMachine.cancel();
    
    // 7. Успешная покупка после добавления денег
    cout << "\n=== ТЕСТ 7: Добавление денег и успешная покупка ===" << endl;
    coffeeMachine.coin(40);
    coffeeMachine.choice(3);
    
    // 8. Выключение автомата
    cout << "\n=== ТЕСТ 8: Выключение автомата ===" << endl;
    coffeeMachine.off();
    
    // 9. Попытка использования после выключения
    cout << "\n=== ТЕСТ 9: Попытка использования после выключения ===" << endl;
    coffeeMachine.coin(50);
    
    // 10. Повторное включение и быстрая покупка
    cout << "\n=== ТЕСТ 10: Повторное включение и покупка ===" << endl;
    coffeeMachine.on();
    coffeeMachine.coin(65);
    coffeeMachine.choice(7);
    
    // 11. Демонстрация отмены после выбора
    cout << "\n=== ТЕСТ 11: Отмена после выбора напитка ===" << endl;
    coffeeMachine.coin(55);
    coffeeMachine.choice(5);
    coffeeMachine.cancel();
    
    // 12. Выключение
    cout << "\n=== ТЕСТ 12: Финальное выключение ===" << endl;
    coffeeMachine.off();

    return 0;
}
