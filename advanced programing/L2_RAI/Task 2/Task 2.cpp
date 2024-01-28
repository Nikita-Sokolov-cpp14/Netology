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
            arr = new int[size] ();
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

    void operator=(Int_arr& right) {
        delete[] arr;
        size = right.size;
        real_size = right.real_size;
        arr = new int[size];
        for (int i = 0; i < real_size; ++i) {
            arr[i] = right.arr[i];
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
        Int_arr new_arr(2);

        arr.add_elem(1);
        arr.add_elem(4);
        arr.add_elem(155);

        new_arr.add_elem(44);
        new_arr.add_elem(34);

        std::cout << arr[0] << std::endl;
        std::cout << arr[1] << std::endl;

        arr = new_arr;

        std::cout << arr[0] << std::endl;
        std::cout << arr[1] << std::endl;

        std::cout << new_arr[0] << std::endl;
        std::cout << new_arr[1] << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
