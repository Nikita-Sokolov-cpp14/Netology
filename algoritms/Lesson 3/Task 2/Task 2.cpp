#include <iostream>
#include <windows.h>

void swap(int* a, int* b) {
    int buf = *a;
    *a = *b;
    *b = buf;
}

int pivoting(int* arr, int size, int pi) {
    int elem = arr[pi];
    int left = 0, right = size - 1;

    while (true) {
        while (arr[left] < elem) {
            left++;
        }
        while (arr[right] > elem) {
            right--;
        }
        if (left >= right) {
            return left;
        }
        swap(&arr[left], &arr[right]);
        right--;
        left++;
    }
}

void quick_sort(int* arr, int size) {
    if (size > 1) {
        int pi = size / 2;
        int border;
        border = pivoting(arr, size, pi);
        quick_sort(arr, border);
        quick_sort(arr + border, size - border);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr[] = { 124, 66, 88, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quick_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
