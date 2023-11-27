#include "Lib/class.h"
#include <iostream>
#include <string>
#include <Windows.h>

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::string Name;
	std::cout << "¬ведите им€: ";
	std::cin >> Name;
	Leaver L1;
	std::cout << L1.leave(Name) << std::endl;
	system("pause");
	return 0;
}