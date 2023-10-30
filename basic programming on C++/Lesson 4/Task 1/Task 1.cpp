#include <iostream>
#include <string>
#include <fstream>

class Adress {
private:
    std::string city;
    std::string street;
    int house;
    int appart;
public:
    void set_adress(std::string city, std::string street, int house, int appart)
    {

    }
};

int main()
{
    int N;
    std::string kursor;
    std::ifstream input_file("int.txt");
    if (!input_file.is_open()) {
        std::cout << "Ошибка. Файл не найден!";
        return 1;
    }
    input_file >> kursor;
    N = std::stoi(kursor);
    Adress* adress = new Adress[N];
    

    return 0;
}

