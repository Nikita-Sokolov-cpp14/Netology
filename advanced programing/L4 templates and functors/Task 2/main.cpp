#include <iostream>

template <class T>
class Buf_arr {
private:
    T* arr;
    int N;
public:
    Buf_arr(T* line_table, int num_elem) : arr(line_table), N(num_elem) {};
    T& operator[](int index) {
        if (index >= N || index < 0) {
            throw std::invalid_argument("Invalid_index_in_line");
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index >= N || index < 0) {
            throw std::invalid_argument("Invalid_index_in_line");
        }
        return arr[index];
    }
};

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

    Buf_arr<T> operator[](int i) {
        if (i >= num_lines || i < 0) {
            throw std::invalid_argument("Invalid_index_in_column");
        }

        Buf_arr<T> line(table[i], num_columns);
        return line;
    }

    const Buf_arr<const T> operator[](int i) const {
        if (i >= num_lines || i < 0) {
            throw std::invalid_argument("Invalid_index_in_column");
        }

        Buf_arr<const T> line(table[i], num_columns);
        return line;
    }

    const int size() {
        return num_columns * num_lines;
    }

    void operator=(Table& right) {
        for (int i = 0; i < num_lines; ++i) {
            delete[] table[i];
        }
        delete[] table;

        num_lines = right.num_lines;
        num_columns = right.num_columns;

        table = new T* [num_lines];
        for (int i = 0; i < num_lines; ++i) {
            table = new T [num_columns];
        }
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
    Table<int> table(n, m);

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

        //std::cout << table[9][1] << std::endl;
        std::cout << table[1][9] << std::endl;

    }
    catch (std::invalid_argument& inval_arg) {
        std::cout << inval_arg.what() << std::endl;
    }


    const Table<char> table_2(2, 2);
    //table_2[0][0] = 'a';

    std::cout << typeid(table_2).name() << std::endl;
    std::cout << typeid(table_2[0]).name() << std::endl;
    std::cout << typeid(table_2[0][0]).name() << std::endl;

    auto const value = table_2[0]; //?
    //std::cout << value[0] << std::endl;

    //value = b;

    return 0;
}
