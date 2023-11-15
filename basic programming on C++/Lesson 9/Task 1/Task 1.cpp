#include <iostream>
#include <string>

class bad_length : public std::exception {
public:
    const char* what() const override { return "Вы ввели строку запретной длины."; }
};


int function(std::string str, int forbidden_length) {
    int len = str.length();
    if (len == forbidden_length) {
        throw bad_length();
    }
    return len;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str;
    int error_len;
    
    do {
        std::cout << "Введите запретную длину: ";
        std::cin >> error_len;
        std::cout << "Введите слово: ";
        std::cin >> str;
        try {
            std::cout << "Длина слова " << str << " равна " << function(str, error_len) << std::endl;
        }
        catch (const bad_length& e) {
            std::cout << e.what() << " До свидания." << std::endl;
            break;
        }
    } while (true);
    return 0;
}
