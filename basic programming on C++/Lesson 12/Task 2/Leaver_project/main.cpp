#include "class.h"
#include <Windows.h>

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);	
	SetConsoleOutputCP(1251);

	std::string Name;
	std::cout << "¬ведите им€: ";
	std::cin >> Name;
	Leaver L1;
	std::cout << L1.leave(Name) <<std::endl;
	return 0;
}