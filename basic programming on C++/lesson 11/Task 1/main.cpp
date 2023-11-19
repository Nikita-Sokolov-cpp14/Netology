#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::string Name;
	std::cout << "Введите ваше имя: ";
	std::cin >> Name;
	std::cout << "Здравствуйте, " << Name << "!" << std::endl;
	return 0;
}