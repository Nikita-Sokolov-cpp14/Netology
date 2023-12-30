#include <iostream>

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
int* append_to_dynamic_array(int* arr,int* size_logic,int* size_fact,int add_elem) {
    if (*size_logic == *size_fact) {
        int* new_arr = new int[2 * *size_fact];
        for (int i = 0; i < *size_logic; ++i) {
            new_arr[i] = arr[i];
        }
        new_arr[*size_logic] = add_elem;
        (*size_logic)++;
        *size_fact = *size_fact * 2;
        delete[] arr;
        arr = new_arr;
    }
    else {
        arr[*size_logic] = add_elem;
        (*size_logic)++;
    }
    return arr;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int size_fact = 0;
    int size_logic = 0;
    int add_elem = 0;

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

    std::cout << "Введите элемент для добавления: ";
    std::cin >> add_elem;
    while (add_elem != 0) {
        arr = append_to_dynamic_array(arr, &size_logic, &size_fact, add_elem);
        print_dynamic_array(arr, size_logic, size_fact);
        std::cout << "Введите элемент для добавления: ";
        std::cin >> add_elem;
    }
    print_dynamic_array(arr, size_logic, size_fact);
    std::cout << "До свидания!" << std::endl;

    delete[] arr;
    return 0;
}
