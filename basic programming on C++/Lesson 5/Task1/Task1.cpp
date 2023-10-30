#include <iostream>
#include <string>
#include <fstream>

class Adress {
private:
    std::string city;
    std::string street;
    int house;
    int apart;
public:
    void set_city(std::string city) { this->city = city; }
    void set_street(std::string street) { this->street = street; }
    void set_house(int house) { this->house = house; }
    void set_apart(int apart) { this->apart = apart; }

    std::string get_city() { return this->city; }
    std::string get_street() { return this->street; }
    int get_house() { return this->house; }
    int get_apart() { return this->apart; }
};

int main()
{
    setlocale(LC_ALL, "Russian");


    int N;
    std::string kursor;
    std::ifstream init_file("in.txt");
    std::ofstream output_file("out.txt");

    if (!init_file.is_open()) {
        std::cout << "Ошибка. Файл не найден!";
        return 1;
    }

    init_file >> kursor;
    N = std::stoi(kursor);

    Adress *adresses = new Adress[N];
    for (int i = 0; i < N; ++i) {
        init_file >> kursor;
        adresses[i].set_city(kursor);
        init_file >> kursor;
        adresses[i].set_street(kursor);
        init_file >> kursor;
        adresses[i].set_house(std::stoi(kursor));
        init_file >> kursor;
        adresses[i].set_apart(std::stoi(kursor));
    }
    init_file.close();

    output_file << std::to_string(N) << std::endl;
    for (int i = N - 1; i >= 0; --i) {
        output_file << adresses[i].get_city() << ", ";
        output_file << adresses[i].get_street() << ", ";
        output_file << std::to_string(adresses[i].get_house()) << ", ";
        output_file << std::to_string(adresses[i].get_apart()) << "\n";
    }
    output_file.close();
    delete [] adresses;
    return 0;
}
