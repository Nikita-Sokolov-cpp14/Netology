#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <set>

template<class T>
void print_cont(const T& container) {

    auto it = container.begin();
    while (it != container.end()) {
        std::cout << *it << "\t";
        ++it;
    }
}

template<class T, class U>
void print_cont(const std::map<T, U> container) {

    for (const auto& value : container) {
        std::cout << value.first << ": " << value.second << "\t";
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4 };
    std::forward_list<int> forw_list = {10, 20, 30, 40};
    std::list<int> lst = { 10, 20, 30, 40 };
    std::set<char> st= { 'a', 'b', 'c', 'd'};
    std::map<char, int> mp;

    mp['a'] = 1;
    mp['b'] = 3;
    mp['r'] = 7;
    mp['z'] = 5;

    std::cout << "vector : ";
    print_cont<std::vector<int>>(vec);

    std::cout << "\nforward list : ";
    print_cont<std::forward_list<int>>(forw_list);

    std::cout << "\nlist : ";
    print_cont<std::list<int>>(lst);

    std::cout << "\nset : ";
    print_cont<std::set<char>>(st);

    std::cout << "\nmap : ";
    print_cont<char, int>(mp);

    return 0;
}
