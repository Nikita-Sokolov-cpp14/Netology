#include <iostream>
#include <Windows.h>

class Int_arr {
private:
    int size;
    int real_size;
    int* arr;

public:
    Int_arr(int size) {
        if (size <= 0) {
            throw std::exception("Размер должен быть положительным!");
        }
        else {
            this->size = size;
            real_size = 0;
            arr = new int[size]();
        }
    }

    ~Int_arr() {
        delete[] arr;
    }

    void add_elem(int elem) {
        if (real_size >= size) {
            throw std::exception("Размер превышен!");
        }
        else {
            arr[real_size] = elem;
            real_size++;
        }
    }

    int operator[](int i) {
        if (i > size || i < 0) {
            throw std::exception("Неверный индекс!");
        }
        else {
            return arr[i];
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try {
        Int_arr arr(5);
        arr.add_elem(1);
        arr.add_elem(4);
        arr.add_elem(155);
        arr.add_elem(14);
        arr.add_elem(15);
        std::cout << arr[1] << std::endl;
        std::cout << arr[7] << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
