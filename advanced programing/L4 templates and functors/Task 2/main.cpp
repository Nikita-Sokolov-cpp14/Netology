#include <iostream>

template<class T>
class Table {
protected:
    int num_lines;
    int num_columns;
    T** table;
public:
    Table(int n, int m) : num_lines(n), num_columns(m) {
        table = new T* [num_lines];
        for (int i = 0; i < num_lines; ++i) {
            table[i] = new T[num_columns];
        }
    }

    T* operator[](int i) {
        if (i >= num_lines || i < 0) {
            throw std::invalid_argument("Invalid_index");
        }

        return table[i];
    }

    const T* operator[](int i) const {
        return table[i];
    }


    const int size() {
        return num_columns * num_lines;
    }

    ~Table() {
        for (int i = 0; i < num_lines; ++i) {
            delete[] table[i];
        }
        delete[] table;
    }
};


int main()
{
    int n = 2, m = 3;
    Table  <int>table(n, m);

    try {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                table[i][j] = 3 * i + 2 * j;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << table[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        std::cout << table[9][1] << std::endl;

    }
    catch (std::invalid_argument& inval_arg) {
        std::cout << inval_arg.what() << std::endl;
    }




    return 0;
}
