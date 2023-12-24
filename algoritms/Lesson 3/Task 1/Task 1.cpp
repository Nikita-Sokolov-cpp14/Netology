#include <iostream>
#include <windows.h>

void merge(int* arr, int* arr_left, int* arr_right, int size) {
    int size_left = size / 2, i_left = 0;
    int size_right = size - size / 2, i_right = 0;
    int i = 0;

    while ( i_left <= size_left - 1 || i_right <= size_right - 1) {
        if (i_right == size_right) {
            arr[i] = arr_left[i_left];
            i_left++;
        }
        else if (i_left == size_left) {
            arr[i] = arr_right[i_right];
            i_right++;
        }
        else if (arr_left[i_left] <= arr_right[i_right]) {
            arr[i] = arr_left[i_left];
            i_left++;
        }
        else {
            arr[i] = arr_right[i_right];
            i_right++;
        }
        i++;
    }
}

void merge_sort(int* arr, int size) {
    if (size > 1) {
        int new_size = size / 2;
        int* arr_left = new int[new_size];
        int* arr_right = new int[size - new_size];
        
        for (int i = 0; i < new_size; ++i) {
            arr_left[i] = arr[i];
        }
        for (int i = 0; i < size - new_size; ++i) {
            arr_right[i] = arr[i + new_size];
        }

        merge_sort(arr_left, new_size);
        merge_sort(arr_right, size - new_size);
        merge(arr, arr_left, arr_right, size);

        delete[] arr_left;
        delete[] arr_right;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    merge_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
