#include <iostream>
#include <vector>

template <class T>
T square(T value) {
    return value * value;
}
template <class T>
void square(std::vector<T>& vec) {
    for (auto& value : vec) {
        value = value * value;
    }
}

int main()
{
    double a = 12.4;
    int b = 10;

    std::cout << "a = " << a << "; a^2 = " << square(a) << std::endl;
    std::cout << "b = " << b << "; b^2 = " << square(b) << std::endl;

    std::vector<int> vec_1 = {1, 2, 3, 4, 5};
    std::vector<double> vec_2 = {1.1, 2.2, 3.3, 4.423, 5.987654322};

    std::cout << "vec_1 = { ";
    for (const auto& value : vec_1) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;

    square(vec_1);

    std::cout << "vec_1 ^ 2 = { ";
    for (const auto& value : vec_1) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "vec_2 = { ";
    for (const auto& value : vec_2) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;

    square(vec_2);

    std::cout << "vec_2 ^ 2 = { ";
    for (const auto& value : vec_2) {
        std::cout << value << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
