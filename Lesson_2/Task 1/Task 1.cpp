#include <iostream>

int main()
{
    setlocale(LC_ALL, "russian");
    enum class months
    {
        jan = 1,
        feb,
        mar,
        apr,
        may,
        jun,
        jul,
        aug,
        sep,
        oct,
        nov,
        dec
    };
    int number;
    months mon;
    do
    {
        std::cout << "Введите номер месяца: ";
        std::cin >> number;
        if (number != 0)
        {
            mon = static_cast<months>(number);
            switch (mon)
            {
            case months::jan: std::cout << "Январь\n"; break;
            case months::feb: std::cout << "Февраль\n"; break;
            case months::mar: std::cout << "Март\n"; break;
            case months::apr: std::cout << "Апрель\n"; break;
            case months::may: std::cout << "Май\n"; break;
            case months::jun: std::cout << "Июнь\n"; break;
            case months::jul: std::cout << "Июль\n"; break;
            case months::aug: std::cout << "Август\n"; break;
            case months::sep: std::cout << "Сентябрь\n"; break;
            case months::oct: std::cout << "Октябрь\n"; break;
            case months::nov: std::cout << "Ноябрь\n"; break;
            case months::dec: std::cout << "Декабрь\n"; break;
            default: std::cout << "Введите правильный номер!" << std::endl;
            }
        }
        else
        {
            std::cout << "До свидания" << std::endl;
        }
    } while (number != 0);
    return 0;
}