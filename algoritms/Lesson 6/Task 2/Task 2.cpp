#include <iostream>
#include <string>
#include <windows.h>

long long pow(int x, int stepen) {
	if (stepen == 0) {
		return 1;
	}
	return x * pow(x, stepen - 1);
}

int real_string_hash(std::string str, int p, int n) {
	long long hash = 0;
	int size = str.length();

	for (int i = 0; i < size; ++i) {
		///std::cout << static_cast<int>(str[i]) << std::endl;
		hash = hash + static_cast<int>(str[i]) * pow(p, i);
	}
	//std::cout << hash << std::endl;
	
	return static_cast<int>(hash % n);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string str;
	int hash = 0;
	int p = 0, n = 0;

	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;

	do {
		std::cout << "Введите строку: ";
		std::cin >> str;

		hash = real_string_hash(str, p, n);
		std::cout << "Хэш строки " << str << " = " << hash << std::endl;

	} while (str != "exit");

	return 0;
}