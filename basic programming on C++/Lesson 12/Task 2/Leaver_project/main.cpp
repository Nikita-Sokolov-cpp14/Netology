#include "class.h"
#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::string Name;
	std::cout << "¬ведите им€: ";
	std::cin >> Name;
	Leaver L1;
	std::cout << L1.leave(Name) << std::endl;
	return 0;
}