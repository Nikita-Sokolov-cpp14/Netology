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

    std::lock(d1.mut, d2.mut);
    std::lock_guard  lg_1(d1.mut, std::adopt_lock);
    std::lock_guard  lg_2(d2.mut, std::adopt_lock);

    Data buf(d1);
    d1 = d2;
    d2 = buf;
}

void swap_scoped(Data& d1, Data& d2) {

    std::scoped_lock sl1(d1.mut, d2.mut);

    Data buf(d1);
    d1 = d2;
    d2 = buf;
}

void swap_unique(Data& d1, Data& d2) {

    std::unique_lock ul_1(d1.mut, std::defer_lock);
    std::unique_lock ul_2(d2.mut, std::defer_lock);
    std::lock(ul_1, ul_2);

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

    swap_lock(data_1, data_2);

    std::cout << "swap_lock" << std::endl;
    data_1.print_data();
    data_2.print_data();

    swap_scoped(data_1, data_2);

    std::cout << "swap_scoped" << std::endl;
    data_1.print_data();
    data_2.print_data();

    swap_unique(data_1, data_2);

    std::cout << "swap_unique" << std::endl;
    data_1.print_data();
    data_2.print_data();

    return 0;
}
