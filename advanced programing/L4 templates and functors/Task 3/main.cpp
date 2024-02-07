#include <iostream>

class Counter {
private:
    int count_3;
    int sum_3;

public:
    Counter() : count_3(0), sum_3(0) {}

    int get_count() { return count_3; }

    int get_sum() { return sum_3; }

    void operator() (int value) {
        if (value % 3 == 0) {
            sum_3 += value;
            count_3++;
        }
    }
};

int main()
{
    Counter ct;

    int value;

    std::cout << "Enter value: ";
    std::cin >> value;
    while(value > 0) {
        ct(value);

        std::cout << "enter value and 0 for end: ";
        std::cin >> value;
    }

    std::cout << "count = " << ct.get_count() << std::endl;
    std::cout << "sum = " << ct.get_sum() << std::endl;

    return 0;
}
