#include <iostream>
#include <windows.h>
#include <string>

int log_2(int n) {
	if (n == 1) {
		return 0;
	}
	return 1 + log_2(n / 2);
}
void print_pyramid(int* arr, int size) {
	int layer = 0;
	std::cout << "Пирамида:" << std::endl;

	for (int i = 0; i < size; ++i) {
		layer = log_2(i + 1) + 1;
		if (i == 0) {
			std::cout << layer - 1 << " ";
			std::cout << "root " << arr[0] << std::endl;
		}
		if (2 * i + 1 < size) {
			std::cout << layer << " ";
			std::cout << "Left(" << arr[i] << ") ";
			std::cout << arr[2 * i + 1] << std::endl;
		}
		if (2 * i + 2 < size) {
			std::cout << layer << " ";
			std::cout << "Right(" << arr[i] << ") ";
			std::cout << arr[2 * i + 2] << std::endl;
		}
	}
}
void print_position(int* arr, int position) {
	std::cout << "Вы находитесь здесь: " << log_2(position + 1) << " ";
	if (position == 0) {
		std::cout << "root " << arr[position] << std::endl;
	}
	else {
		if (position % 2 == 0) {
			std::cout << "right(";
		}
		else {
			std::cout << "left(";
		}
		std::cout << arr[(position - 1) / 2] << ")" << " ";
		std::cout << arr[position] << std::endl;
	}
}
bool step(int* arr,int size,int* position, std::string comand) {
	if (comand == "left") {
		if (*position * 2 + 1 < size) {
			*position = *position * 2 + 1;
			return true;
		}
		else {
			throw std::logic_error("Левого потомка нет!");
		}
	}
	else if (comand == "right") {
		if (*position * 2 + 2 < size) {
			*position = *position * 2 + 2;
			return true;
		}
		else {
			throw std::logic_error("Правого потомка нет!");
		}
	}
	else if (comand == "up") {
		if (*position != 0) {
			*position = (*position - 1) / 2;
			return true;
		}
		else {
			throw std::logic_error("Отсутствует родитель!");
		}
	}
	else if (comand == "exit") {
		return false;
	}
	else {
		throw std::logic_error("Неизвестная команда!");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int arr[] = { 1, 3, 6, 5, 9, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int position = 0;
	std::string comand;

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_pyramid(arr, size);

	print_position(arr, position);

	bool is_ok;

	do {
		std::cout << "Введите команду: ";
		std::cin >> comand;

		try {
			is_ok = step(arr, size, &position, comand);
			if (is_ok) {
				std::cout << "Ok" << std::endl;
			}
		}
		catch (std::logic_error& err) {
			std::cout << err.what() << std::endl;
		}

		print_position(arr, position);
	} while (is_ok);
	return 0;
}
