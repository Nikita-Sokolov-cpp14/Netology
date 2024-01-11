#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

void deep_crowl(int** matrix, int v, int* visited, int N, int number_comp) {
    visited[v] = number_comp;
    for (int i = 0; i < N; ++i) {
        if (matrix[v][i] == 1 && visited[i] == 0) {
            deep_crowl(matrix, i, visited, N, number_comp);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream input_file("input.txt");
    std::string kursor;
    int N;
    int** arr;
    int* connect_comps;
    int number_comp = 0;

    if (input_file.is_open()) {
        input_file >> kursor;
        N = std::stoi(kursor);

        arr = new int* [N];
        for (int i = 0; i < N; ++i) {
            arr[i] = new int[N];
        }

        connect_comps = new int[N]();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                input_file >> kursor;
                arr[i][j] = std::stoi(kursor);
            }
        }

        for (int i = 0; i < N; ++i) {
            if (connect_comps[i] == 0) {
                number_comp++;
                deep_crowl(arr, i, connect_comps, N, number_comp);
            }
        }

        std::cout << "принадлежность вершин компонентам связанности: " << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << i + 1 << " - " << connect_comps[i] << std::endl;
        }
        std::cout << "Количество компоннтов связанности в графе: " << number_comp << std::endl;
    }

    return 0;
}