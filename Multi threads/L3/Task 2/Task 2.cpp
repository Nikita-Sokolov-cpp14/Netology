#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include <thread>

int elems_in_block = 4;

void calc_foo(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end) {
    
    while (it_begin != it_end) {
        *it_begin = *it_begin * 2;
        it_begin++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void for_each(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end,
        void(*foo)(std::vector<int>::iterator, std::vector<int>::iterator)) {

    int i = 1;
    std::vector<int>::iterator it_buf = it_begin;
    while (i != elems_in_block && it_buf != it_end) {
        i++;
        it_buf++;
    }

    auto calc{std::async(foo, it_begin, it_buf)};

    if (it_buf != it_end) {
        for_each(it_buf, it_end, foo);
        it_buf++;
    }

    calc.wait();
}

void for_each_one_thread(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end,
    void(*foo)(std::vector<int>::iterator, std::vector<int>::iterator)) {
    
    int i = 1;
    std::vector<int>::iterator it_buf = it_begin;
    while (i != elems_in_block && it_buf != it_end) {
        i++;
        it_buf++;
    }

    foo(it_begin, it_buf);

    if (it_buf != it_end) {
        for_each_one_thread(it_buf, it_end, foo);
        it_buf++;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> vec;
    for (int i = 0; i < 30; ++i) {
        vec.push_back(i);
    }

    std::cout << "Контейнер до преобразования:" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::steady_clock::now();

    //for_each_one_thread(vec.begin(), vec.end(), calc_foo);
    for_each(vec.begin(), vec.end(), calc_foo);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = end - start;

    std::cout << "Контейнер после преобразования" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Время выполнения = " << dur.count() << std::endl;

    return 0;
}
