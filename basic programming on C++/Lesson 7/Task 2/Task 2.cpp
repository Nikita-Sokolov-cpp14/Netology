#include <iostream>
#include "counter.h"
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    Counter counter;
    std::string set_init;
    int initial;
    char comand;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите Yes или No: ";
    std::cin >> set_init;
    if (set_init == "Yes") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial;
        counter.set_count(initial);
    }
    else {
        std::cout << "Выбрано значение по умолчанию = 1" << std::endl;
    }

    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> comand;
    counter.step(comand);

    while (comand != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> comand;
        counter.step(comand);
    }
    return 0;
}
