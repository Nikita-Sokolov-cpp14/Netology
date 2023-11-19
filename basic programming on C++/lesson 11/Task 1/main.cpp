#include <iostream>
#include <string>

int main () {
    setlocale(LC_ALL, "Russian");
    std::string Name;
    //std::cout << "Введите имя: ";
    std::cout << "Enter your name: ";
    std::cin >> Name;
    //std::cout << "Здравствуйте, " << Name <<"!";
    std::cout << "Hello, " << Name <<"!";
    return 0;
}