#include <iostream>

template <class T>
class unique_ptr {
private:
    T* ptr;

public:
    unique_ptr(T* simple_ptr) : ptr(simple_ptr) {
        ptr = new T;
    }

    unique_ptr(const unique_ptr<T>& un_ptr) = delete;
    unique_ptr<T>& operator=(const unique_ptr<T>& un_ptr) = delete;

    T& operator*() {
        return *ptr;
    }

    T* release() {
        T* rel_ptr = new T;
        *rel_ptr = *ptr;

        delete ptr;

        return rel_ptr;
    }

    ~unique_ptr() {
        delete ptr;
    }
};

int main()
{
    unique_ptr<int> ptr_1(new int);
    *ptr_1 = 12;
    std::cout << *ptr_1 << std::endl;

    //unique_ptr<int> ptr_2(ptr_1);
    unique_ptr<int> ptr_2(new int);
    *ptr_2 = 8;
    //ptr_2 = ptr_1;

    int* simple_ptr = ptr_2.release();
    std::cout << *simple_ptr;

    return 0;
}
