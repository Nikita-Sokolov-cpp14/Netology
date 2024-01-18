#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream init_file("input.txt");
    if (init_file.is_open()) {
        std::string kursor;
        int N;
        int** matrix;
        bool flag = 0;

        init_file >> kursor;
        N = std::stoi(kursor);

        matrix = new int*[N];
        for( int i = 0; i < N; ++i) {
            matrix[i] = new int[N];
        }

        for( int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                init_file >> kursor;
                matrix[i][j] = std::stoi(kursor);
            }
        }

        std::cout << "Текстовый вид орграфа" << std::endl;
        for(int i = 0; i < N; ++i) {
            flag = 0;
            std::cout << i << ": ";
            for(int j = 0; j < N; ++j) {
                if (matrix[i][j] == 1) {
                    flag = 1;
                    std::cout << j + 1 << " ";
                }
            }
            if (!flag) { std::cout << "нет"; }
            std::cout << std::endl;
        }

        for( int i = 0; i < N; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    return 0;
}
