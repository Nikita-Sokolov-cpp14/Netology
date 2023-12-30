#include <iostream>
#include <string>
#include <Windows.h>

void set_sizes(int* size_fact, int* size_logic) {
    std::cout << "Введите фактический размер массива: ";
    std::cin >> *size_fact;
    std::cout << "Введите логический размер массива: ";
    std::cin >> *size_logic;

    if (*size_logic > *size_fact) {
        throw std::length_error("Ошибка! Логический размер больше фактического! ");
    }
}
void set_arr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Ввдите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    std::cout << std::endl;
}
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}
int* remove_dynamic_array_head(int* arr, int* size_logic, int* size_fact) {
    if (*size_logic == 0) {
        throw std::logic_error("Невозможно удалить первый элемент, так как массив пустой!");
    }
    else {
        if (*size_logic - 1 > *size_fact / 3 || *size_fact == 1 || *size_fact == 2) {
            int* new_arr = new int[*size_fact];
            for (int i = 1; i < *size_logic; ++i) {
                new_arr[i - 1] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            (*size_logic)--;
        }
        else {
            int* new_arr = new int[*size_fact / 3];
            for (int i = 0; i < *size_logic - 1; ++i) {
                new_arr[i] = arr[i + 1];
            }
            delete[] arr;
            arr = new_arr;
            (*size_logic)--;
            *size_fact = *size_fact / 3;
        }
    }
    return arr;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int size_fact = 0;
    int size_logic = 0;
    std::string ans = "Да";

    try {
        set_sizes(&size_fact, &size_logic);
    }
    catch (std::length_error& err) {
        std::cout << err.what();
        set_sizes(&size_fact, &size_logic);
    }

    int* arr = new int[size_fact];
    set_arr(arr, size_logic);

    print_dynamic_array(arr, size_logic, size_fact);

    while (ans != "Нет") {
        std::cout << "Удалить первый элемент? Введите Да или Нет: ";
        std::cin >> ans;
        if (ans != "Нет") {
            try {
                arr = remove_dynamic_array_head(arr, &size_logic, &size_fact);
                print_dynamic_array(arr, size_logic, size_fact);
            }
            catch (std::logic_error& error) {
                std::cout << error.what() << std::endl;;
                ans = "Нет";
            }
        }
    }

    print_dynamic_array(arr, size_logic, size_fact);
    std::cout << "До свидания!" << std::endl;

    delete[] arr;
    return 0;
}
