#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::string Name;
	std::cout << "������� ���� ���: ";
	std::cin >> Name;
	std::cout << "������������, " << Name << "!" << std::endl;
	return 0;
}