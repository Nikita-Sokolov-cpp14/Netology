#include <iostream>
#include <string>
#include <windows.h>

int simple_string_hash(std::string str) {
	int hash = 0;
	int size = str.length();

	for (int i = 0; i < size; ++i) {
		hash = hash + static_cast<int>(str[i]);
	}

	return hash;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string str;
	int hash = 0;

	do {
		std::cout << "Введите строку: ";
		std::cin >> str;

		hash = simple_string_hash(str);
		std::cout << "Наивный хэш строки " << str << " = " << hash << std::endl;

	} while (str != "exit");

    return 0;
}
