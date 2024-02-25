#include <iostream>
#include <vector>

template<class T>
void move_vectors(std::vector<T>& one, std::vector<T>& two) {
    
    two = std::move(one);
}

int main()
{
    std::vector<int> a = { 1, 2, 3, 4,5 };
    std::vector<int> b;

    //b = move(a); ???
    move_vectors(a, b);

    for (const auto& val : b) {
        std::cout << val << "\t";
    }
    std::cout << std::endl;

    return 0;
}
