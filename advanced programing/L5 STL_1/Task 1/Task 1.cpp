#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
    std::string str;

    std::cout << "Enter str: ";
    std::getline(std::cin, str); 

    std::map<char, int> counter;

    for (int i = 0; i < str.length(); ++i) {
        counter[str[i]]++;
    }

    std::cout << "Before reading:" << std::endl;
    for (const auto& value : counter) {
        std::cout << value.first << ": " << value.second << std::endl;
    }

    std::vector<std::pair<char, int>> sorted_counter;

    for (const auto& value : counter) {
        sorted_counter.push_back(value);
    }

    std::sort(sorted_counter.begin(), sorted_counter.end(),
        [](const std::pair<char, int>& left, const std::pair<char, int>& right) {
            return left.second > right.second;
        }
    );

    std::cout << "Before sorting:" << std::endl;
    for (const auto& value : sorted_counter) {
        std::cout << value.first << ": " << value.second << std::endl;
    }

    return 0;
}
