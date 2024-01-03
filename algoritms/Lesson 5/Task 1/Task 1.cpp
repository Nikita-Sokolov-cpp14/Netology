#include <iostream>
#include <windows.h>

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
			std::cout << layer  - 1 << " ";
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

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_pyramid(arr, size);

	return 0;
}
