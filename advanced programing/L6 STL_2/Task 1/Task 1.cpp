#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

template<class T>
std::vector<T> unique_ver_1(std::vector<T>& vec) {
    std::unordered_map<T, int> buf;

    for (const auto& val : vec) {
        buf[val]++;
    }

    std::vector<T> uniq_vec;

    for (const auto& pair : buf) {

        if (pair.second == 1) {
            uniq_vec.push_back(pair.first);
        }
    }

    return uniq_vec;
}



int main()
{
    std::vector<int> vec_1 = { 1, 2, 3, 2, 2, 6, 3, 2 };

    std::vector<int> vec_3 = unique_ver_1<int>(vec_1);

    for (const auto& value : vec_1) {
        std::cout << value << "\t";
    }

    std::cout << "\nafter unique" << std::endl;
    for (const auto& value : vec_3) {
        std::cout << value << "\t";
    }
    std::cout << std::endl;


    return 0;
}