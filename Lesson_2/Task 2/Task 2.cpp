#include <iostream>
#include <string>

struct bank_acc
{
    int number;
    std::string name;
    float balance;
};


void change_bal(bank_acc* client, float new_balance)
{
    client->balance = new_balance;
}

int main()
{
    float new_balance;
    setlocale(LC_ALL, "russian");

    bank_acc Client_1;
    std::cout << "Введите номер счёта: ";
    std::cin >> Client_1.number;
    std::cout << "Введите имя владельца: ";
    std::cin >> Client_1.name;
    std::cout << "Введите баланс: ";
    std::cin >> Client_1.balance;

    std::cout << "Введите новый баланс:";
    std::cin >> new_balance;

    change_bal(&Client_1, new_balance);

    std::cout << "Ваш счёт: " << Client_1.name << ", " << Client_1.number << ", " << Client_1.balance;
    return 0;
}
