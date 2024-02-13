#include <iostream>

template <class T>
class vector {
private:
    size_t fact_size;
    size_t logic_size;
    size_t default_size = 5;
    size_t coef_size = 2;
    T* vec;
    
public:
    vector() {
        vec = new T[default_size];
        fact_size = default_size;
        logic_size = 0;
    }

    vector(size_t size) : fact_size(size) {
        logic_size = 0;
        vec = new T[fact_size];
    }

    vector(const vector<T>& right) : logic_size(right.logic_size) {
        fact_size = logic_size * coef_size;
        vec = new T[fact_size];

        for (int i = 0; i < logic_size; ++i) {
            vec[i] = right.vec[i];
        }
    }


     vector<T>& operator=(const vector<T>& right) {

         if (this == &right) {
             return *this;
         }

        logic_size = right.logic_size;
        fact_size = right.fact_size;

        delete[] vec;

        vec = new T[fact_size];

        for (int i = 0; i < logic_size; ++i) {
            vec[i] = right.arr[i];
        }

        return *this;
    }

    T& operator[](size_t index) {
        return vec[index];
    }

    const T& operator[](size_t index) const {
        return vec[index];
    }

    T& at(size_t index) {
        if (index >= logic_size) {
            throw std::invalid_argument("index out of range");
        }

        return vec[index];
    }

    const T& at(size_t index) const {
        if (index >= logic_size) {
            throw std::invalid_argument("index out of range");
        }

        return vec[index];
    }

    const size_t size() { return logic_size; }
    const size_t capacity() { return fact_size; }

    void push_back(T value) {
        if (logic_size == fact_size) {

            fact_size = fact_size * coef_size;
            logic_size++;

            T* new_vec = new T[fact_size];

            for (int i = 0; i < logic_size - 1; ++i) {
                new_vec[i] = vec[i];
            }
            new_vec[logic_size - 1] = value;

            delete[] vec;
            vec = new_vec;
        }
        else {
            vec[logic_size] = value;
            logic_size++;
        }
    }

    void push_front(T value) {
        if (logic_size == fact_size) {
            
            fact_size = fact_size * coef_size;

            T* new_vec = new T[fact_size];

            new_vec[0] = value;
            for (int i = 1; i < logic_size + 1; ++i) {
                new_vec[i] = vec[i - 1];
            }
            logic_size++;

            delete[] vec;
            vec = new_vec;
        }
        else {
            T* new_vec = new T[fact_size];

            new_vec[0] = value;
            for (int i = 1; i < logic_size + 1; ++i) {
                new_vec[i] = vec[i - 1];
            }

            logic_size++;

            delete[] vec;
            vec = new_vec;
        }
    }

    ~vector() {
        delete[] vec;
    }
};


int main()
{
    vector<int> a_1();
    vector<int> a_2(5);

    std::cout << a_2.size() << std::endl;
    std::cout << a_2.capacity() << std::endl;

    a_2.push_back(1);
    a_2.push_back(2);
    a_2.push_back(3);
    a_2.push_back(4);
    a_2.push_back(5);
    a_2.push_back(6);

    std::cout << a_2.size() << std::endl;
    std::cout << a_2.capacity() << std::endl;

    vector<int> a_3(a_2);

    for (int i = 0; i < a_2.size(); ++i) {
        std::cout << a_2[i] << "\t";
    }
    std::cout << std::endl;

    a_3.push_front(7);
    a_3.push_front(8);
    a_3.push_front(9);

    for (int i = 0; i < a_3.size(); ++i) {
        std::cout << a_3[i] << "\t";
    }
    std::cout << std::endl;

    std::cout << a_3.at(1) << std::endl;

    try {
        std::cout << a_3.at(9) << std::endl;
    }
    catch (std::invalid_argument& err) {
        std::cout << err.what() << std::endl;
    }
    
    return 0;
}