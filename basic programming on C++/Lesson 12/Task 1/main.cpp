#include "Lib/class.h"
#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::string Name;
	std::cout << "������� ���: ";
	std::cin >> Name;
	Greeter G1;
	std::cout << G1.greet(Name) << std::endl;
	return 0;
}