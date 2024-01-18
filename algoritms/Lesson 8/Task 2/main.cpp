#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <windows.h>

void topology_sort(int** matrix, int N,int v, int* visited, std::list<int>* ans) {
    visited[v] = 1;
    for (int i = 0; i < N; ++i) {
        if (visited[i] == 0 && matrix[v][i] == 1) {
            topology_sort(matrix, N, i, visited, ans);
        }
    }
    (*ans).push_front(v);
}

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
        int* visited;
        std::list<int> ans;

        init_file >> kursor;
        N = std::stoi(kursor);

        visited = new int[N]();
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
        
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 0) {
                topology_sort(matrix, N, i, visited, &ans);
            }
        }
        
        std::cout << "Топологический порядок вершин: ";
        for (const auto& elem : ans) {
            std::cout << elem + 1 << " ";
        }
        std::cout << std::endl;

        for( int i = 0; i < N; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    return 0;
}
