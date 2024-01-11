#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

void deep_crowl(int** matrix, int v, int* visited, int N) {
    std::cout << v + 1 << " ";
    visited[v] = 1;
    for (int i = 0; i < N; ++i) {
        if (matrix[v][i] == 1 && visited[i] == 0) {
            deep_crowl(matrix,i , visited, N);
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

        std::cout << "Порядок обхода вершин: ";
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) {
                deep_crowl(arr, i, visited, N);
            }
        }
    }

    return 0;
}