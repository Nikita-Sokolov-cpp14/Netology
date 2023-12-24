#include <iostream>
#include <windows.h>

void count_sort(int* arr,int size) {
    int A_min = 10, A_max = 24;
    int* new_arr = new int[A_max - A_min + 1] ();

    for (int i = 0; i < size; ++i) {
        new_arr[arr[i] - A_min]++;
    }

    int i_arr = 0;
    for (int i = 0; i < A_max - A_min + 1; ++i) {
        while (new_arr[i] > 0) {
            arr[i_arr] = i + A_min;
            i_arr++;
            new_arr[i]--;
        }
    }

    delete[] new_arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    count_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
