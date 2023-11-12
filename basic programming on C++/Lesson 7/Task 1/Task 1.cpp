#include "calc.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, y;
    int switcher;
    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;
    Calculator calculator(x, y);

    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> switcher;
    switch (switcher) {
        case 1: calculator.print_sum(); break;
        case 2: calculator.print_diff(); break;
        case 3: calculator.print_mult(); break;
        case 4: calculator.print_div(); break;
        case 5: calculator.print_pow(); break;
        default: std::cout << "Ошибка!" << std::endl; break;
    }

    return 0;
}
