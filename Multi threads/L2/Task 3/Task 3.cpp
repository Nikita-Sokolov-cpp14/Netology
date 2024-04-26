#include <iostream>
#include <thread>
#include <mutex>

class Data {
private:
    int a;
    double b;
public:
    std::mutex mut;

    Data(int a_, double b_) : a(a_), b(b_) {}
    Data(Data& right) {
        a = right.a;
        b = right.b;
    }

    Data& operator=(Data& right) {
        if (&right != this) {
            a = right.a;
            b = right.b;
            return *this;
        }
    }

    void print_data() {
        std::cout << a << "; " << b << std::endl;
    }
};

void swap_lock(Data& d1, Data& d2) {
    d1.mut.lock();
    d2.mut.lock();

    Data buf(d1);
    d1 = d2;
    d2 = buf;

    d1.mut.unlock();
    d2.mut.unlock();
}

void swap_scoped(Data& d1, Data& d2) {

    std::scoped_lock(d1.mut, d2.mut);

    Data buf(d1);
    d1 = d2;
    d2 = buf;
}

void swap_unique(Data& d1, Data& d2) {

    std::unique_lock ul_1(d1.mut);
    std::unique_lock ul_2(d2.mut);

    Data buf(d1);
    d1 = d2;
    d2 = buf;
}

int main()
{
    Data data_1(10, 20);
    Data data_2(63, 12);

    data_1.print_data();
    data_2.print_data();

    swap_unique(data_1, data_2);

    std::cout << std::endl;
    data_1.print_data();
    data_2.print_data();

    return 0;
}
