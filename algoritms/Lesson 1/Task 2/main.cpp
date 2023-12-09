#include <iostream>

int find(int* arr, int n, int point) {
	int elems_more = 0;
	int index = 0;
	int left = 0, right = n - 1;
	int mid = 0;
	if (point <= arr[0]) {
		return 9;
	}
	if (point >= arr[n - 1]) {
		return 0;
	}
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] > point) {
			right = mid;
			index = mid;
		}
		if (arr[mid] <= point) {
			left = mid + 1;
			index = mid + 1;
		}
	}
	elems_more = n - index;
	return elems_more;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
	int point;
	int elems_more = 0;

	const int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Введите точку отсчёта: ";
	std::cin >> point;
	std::cout << "Количество элементов в массиве больших, чем " << point << ": ";
	std::cout << find(arr, n, point) << std::endl;
	return 0;
}