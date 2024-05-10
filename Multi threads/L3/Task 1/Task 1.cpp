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

void sort(std::vector<int> vec, std::promise<std::vector<int>> res) {
    
    for (int i = 0; i < vec.size(); i++) {
        int min = vec[i];
        int min_index = i;

        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < min) {
                min = vec[j];
                min_index = j;
            }
        }
        swap(vec[i], vec[min_index]);
    }

    res.set_value(vec);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "end swap" << std::endl;
}


int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(-20);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);

    std::promise<std::vector<int>> pr;
    auto pr_future(pr.get_future());
    auto calc(std::async(sort, vec, std::move(pr)));

    std::vector<int> ansv = pr_future.get();

    for (const auto& val : ansv) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
