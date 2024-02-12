#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
    int number_elems = 0;
    int value = 0;

    std::cout << "Enter number of elements: ";
    std::cin >> number_elems;

    std::map<int, int> buf_mp;
    std::vector<int> unique_elems;

    std::cout << "Enter " << number_elems << " values" << std::endl;
    for (int i = 0; i < number_elems; ++i) {
        std::cin >> value;
        buf_mp[value]++;

        if (buf_mp[value] == 1) {
            unique_elems.push_back(value);
        }
    }

    std::sort(unique_elems.begin(), unique_elems.end(), [](const int& l,const int& r) {
            return l > r;
        }
    );

    std::cout << "Unique elems: " << std::endl;
    for (const auto& elem : unique_elems) {
        std::cout << elem << std::endl;
    }

    return 0;
}
