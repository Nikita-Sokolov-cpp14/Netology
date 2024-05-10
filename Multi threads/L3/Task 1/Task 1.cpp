#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

void swap(int& a, int& b) {
    int buf = a;
    a = b;
    b = buf;
}

int find_min(const std::vector<int>& vec, int start_pos) {
    int min = vec[start_pos];
    int min_index = start_pos;

    for (int j = start_pos + 1; j < vec.size(); j++) {
        if (vec[j] < min) {
            min = vec[j];
            min_index = j;
        }
    }

    return min_index;
}

void sort(std::vector<int> vec, std::promise<std::vector<int>> res) {
    
    for (int i = 0; i < vec.size(); i++) {
        auto min_index{ std::async(find_min, std::ref(vec), i) };
        swap(vec[i], vec[min_index.get()]);
    }

    res.set_value(vec);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "end swap" << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(-20);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);

    std::cout << "До сортировки:" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;


    std::promise<std::vector<int>> pr;
    auto pr_future(pr.get_future());
    auto calc(std::async(sort, vec, std::move(pr)));

    std::vector<int> ansv = pr_future.get();

    std::cout << "После сортировки:" << std::endl;
    for (const auto& val : ansv) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
