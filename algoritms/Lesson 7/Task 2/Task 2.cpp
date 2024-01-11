#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

class Node {
public:
    int elem;
    Node* next_elem;
    Node* prev_elem;
    Node() {
        elem = 0;
        next_elem = NULL;
        prev_elem = NULL;
    }
};

class LinkedList {
protected:
    int size;
    Node* first_ptr;
    Node* end_ptr;
public:
    LinkedList() {
        size = 0;
        first_ptr = NULL;
        end_ptr = NULL;
    }
};

class Queue : public LinkedList {
public:
    void add(int elem) {
        size++;
        Node* new_elem = new Node;
        new_elem->elem = elem;

        if (size == 1) {
            first_ptr = new_elem;
            end_ptr = new_elem;
        }
        else {
            new_elem->prev_elem = end_ptr;
            end_ptr->next_elem = new_elem;
            end_ptr = new_elem;
        }
    }
    int next() {
        size--;
        int elem = first_ptr->elem;
        Node* buf = first_ptr;
        first_ptr = buf->next_elem;
        delete buf;
        return elem;
    }
    int get_size() {
        return size;
    }
};


void width_traversal(int** matrix, int v, int* visited, int N) {
    Queue* Q1 = new Queue;
    Q1->add(v);

    int vertex = 0;

    while (Q1->get_size() != 0) {
        vertex = Q1->next();
        std::cout << vertex + 1 << " ";
        visited[vertex] = 1;

        for (int i = 0; i < N; ++i) {
            if (matrix[vertex][i] == 1 && visited[i] == 0) {
                Q1->add(i);
                visited[i] = 1;
            }
        }
    }

    delete Q1;
}

int set_n_start() {
    int n_start;
    std::cout << "В графе 7 вершин. Введите номер вершины, с которой начнётся обход: ";
    std::cin >> n_start;
    n_start--;
    if (n_start < 0 || n_start > 6) {
        throw std::invalid_argument("Недопустимый номер вершины!");
    }
    return n_start;
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
    int n_start = 0;

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

        try {
            n_start = set_n_start();
        }
        catch (std::invalid_argument& err) {
            std::cout << err.what() << std::endl;
            n_start = set_n_start();
        }

        std::cout << "Порядок обхода вершин: ";
        width_traversal(arr, n_start, visited, N);

    }

    return 0;
}