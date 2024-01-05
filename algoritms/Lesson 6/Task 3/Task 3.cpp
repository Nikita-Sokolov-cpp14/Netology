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

int find_substring_light_rabin_karp(std::string str, std::string str_key) {
	int len = str.length();
	int len_key = str_key.length();
	int hash = 0;
	int hash_key = simple_string_hash(str_key);
	int index_key = -1;
	bool flag;

	for (int i = 0; i < len - len_key + 1; ++i) {
		if (i == 0) {

			hash = simple_string_hash(str.substr(0, len_key));
		}
		else {
			hash = hash - static_cast<int>(str[i - 1]) + static_cast<int>(str[i + len_key - 1]);
		}

		if (hash == hash_key) {
			flag = true;
			for (int j = 0; j < len_key; ++j) {
				if (str[i + j] != str_key[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return i;
			}
		}
	}

	return index_key;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::string str, str_key;
	int index_key = -1;

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> str;

	do {
		std::cout << "Введите строку, которую нужно найти: ";
		std::cin >> str_key;

		index_key = find_substring_light_rabin_karp(str, str_key);
		if (index_key == -1) {
			std::cout << "Подстрока " << str_key << " не найдена." << std::endl;
		}
		else {
			std::cout << "Подстрока " << str_key << " найдена по индексу " << index_key << std::endl;
		}
		
	} while (str_key != "exit");

	return 0;
}