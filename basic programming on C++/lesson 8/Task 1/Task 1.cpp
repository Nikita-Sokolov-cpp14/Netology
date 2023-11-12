#include <iostream>

#define MODE 1
#if !defined MODE
#error MODE is not defined
#endif

#if MODE == 1
void add() {
    int a, b;
    std::cout << "Раотаю в боеоом режиме" << std::endl;
    std::cout << "Введите 2 числа. Число 1 = ";
    std::cin >> a;
    std::cout << "Число 2 = ";
    std::cin >> b;
    std::cout << "Сумма = " << a + b << std::endl;
}
#endif

int main()
{
    setlocale(LC_ALL, "Russian");
#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    add();
#else
    std::cout << "Неизвестный режим. Завершение работы." << std::endl;
#endif
    return 0;
}