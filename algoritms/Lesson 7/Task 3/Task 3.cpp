#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

void deep_crowl(int** matrix, int v, int* visited, int N, bool* cicle, int prev) {
    visited[v] = 1;
    for (int i = 0; i < N; ++i) {
        if (matrix[v][i] == 1 && visited[i] == 0) {
            deep_crowl(matrix, i, visited, N, cicle, v);
        }
        else if (matrix[v][i] == 1 && visited[i] == 1 && i != prev) {
            *cicle = true;
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
    int* visited;
    bool cicle = false;

    if (input_file.is_open()) {
        input_file >> kursor;
        N = std::stoi(kursor);

        arr = new int* [N];
        for (int i = 0; i < N; ++i) {
            arr[i] = new int[N];
        }

        visited = new int[N]();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                input_file >> kursor;
                arr[i][j] = std::stoi(kursor);
            }
        }

        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) {
                deep_crowl(arr, i, visited, N, &cicle, i);
            }
        }
        
    }

    if (cicle) {
        std::cout << "В графе есть цикл" << std::endl;
    }
    else {
        std::cout << "В графе нет цикла" << std::endl;
    }

    return 0;
}