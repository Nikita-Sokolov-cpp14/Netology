﻿#include <iostream>

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <windows.h>


class Section {
private:
    std::map<std::string, int> int_vals;
    std::map<std::string, double> double_vals;
    std::map<std::string, std::string> string_vals;
    std::map<std::string, int> names;

public:
    void set_vals(std::map<std::string, std::string> init) {

        for (const auto& val_pair : init) {

            int cifrs = 0;
            int dot = 0;

            for (const auto& symb : val_pair.second) {
                if (static_cast<int>(symb) >= static_cast<int>('0') && static_cast<int>(symb) <= static_cast<int>('9')) {
                    cifrs++;
                }
                if (static_cast<int>(symb) == static_cast<int>('.')) {
                    dot++;
                }
            }

            if (cifrs == val_pair.second.length()) {
                names["int " + val_pair.first]++;
                int_vals[val_pair.first] = std::stoi(val_pair.second);
            }
            else if (dot == 1 && cifrs == val_pair.second.length() - 1) {
                names["double " + val_pair.first]++;
                double_vals[val_pair.first] = std::stod(val_pair.second);
            }
            else {
                names["string " + val_pair.first]++;
                string_vals[val_pair.first] = val_pair.second;
            }
        }
    }

    void print() {
        for (const auto& pair : int_vals) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }

        for (const auto& pair : double_vals) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }

        for (const auto& pair : string_vals) {
            std::cout << pair.first << " = " << pair.second << std::endl;
        }
    }

    void print_names() {
        for (const auto& pair : names) {
            std::cout << pair.first << ", " << std::endl;
        }
    }

    template <class T>
    T get_val(std::string name) {

        std::string key = typeid(T).name();
        key = key + " " + name; //иначе выдает ошибку о сумме 2 указателей
       
        if (!names.count(key)) {
            throw std::invalid_argument("переменная " + name + " не найдена");
        }

        T ansv;

        if constexpr (std::is_same_v<T, int>) { ansv =  int_vals[name]; }
        else if constexpr (std::is_same_v<T, double>) { ansv = double_vals[name]; }
        else if constexpr (std::is_same_v<T, std::string>) { ansv = string_vals[name]; }

        return ansv;
    }
};

class Parser {
protected:
    std::map<std::string, std::unique_ptr<Section>> full;
    std::ifstream input_file;
    std::string kursor;

public:
    Parser(std::string filename) { input_file.open(filename); }

    void read_file() {
        if (input_file.is_open()) {


            std::map<std::string, int> count_name_section;
            std::string sec_name;
            int number_line = 0;

            bool flag = 1;

            while (!input_file.eof()) {
                std::map<std::string, std::string> vals;

                if (flag) {
                    std::getline(input_file, kursor, '\n');
                    number_line++;
                }

                if (kursor[0] == '[') {
                    int i = 1;
                    sec_name = "";

                    while (kursor[i] != ']' && i != kursor[i] - 1) {
                        sec_name += kursor[i];
                        if (kursor[i] == ';') {
                            throw std::logic_error("Неверный синтаксис в строке " + std::to_string(number_line));
                        }
                        i++;
                    }

                    if (kursor[i] != ']') {
                        throw std::logic_error("Неверный синтаксис в строке " + std::to_string(number_line));
                    }

                    flag = 1;
                    continue;
                }

                while (kursor[0] != '[') {

                    if (!flag) {
                        std::getline(input_file, kursor, '\n');
                        number_line++;
                    }


                    if (kursor[0] != '[' && kursor[0] != ';' && kursor[0] != '\n') {
                        int pos = kursor.find("=");
                        if (pos == kursor.length()) {
                            throw std::logic_error("Неверный синтаксис в строке " + std::to_string(number_line));
                        }
                        vals[kursor.substr(0, pos)] = kursor.substr(pos + 1, kursor.find(";") - pos - 1);
                    }

                    flag = 0;
                    if (input_file.eof()) {
                        break;
                    }
                }

                if (!vals.empty()) {

                    count_name_section[sec_name]++;

                    if (count_name_section[sec_name] == 1) {

                        full[sec_name] = std::make_unique<Section>();
                        full[sec_name]->set_vals(vals);
                    }
                    else {
                        full[sec_name]->set_vals(vals);
                    }
                }
            }
        }
        else {
            throw std::logic_error("file not found");
        }
    }

    void print() {

        for (const auto& pair : full) {
            std::cout << pair.first << std::endl;
            pair.second->print();
        }
    }

    ~Parser() {
        input_file.close();
    }

    template <class T>
    T get_value(std::string key) {
        std::string name_sec = key.substr(0, key.find('.'));
        std::string name_val = key.substr(key.find('.') + 1, key.length());

        T ansv;

        try {
            ansv = full[name_sec]->get_val<T>(name_val);
        }
        catch (std::logic_error& err) {
            std::cout << err.what() << std::endl;
            std::cout << "Выберите переменную типа " << typeid(T).name() <<  " из доступных:" << std::endl;
            full[name_sec]->print_names();
            std::cin >> name_val;
            ansv = full[name_sec]->get_val<T>(name_val);
        }
        
        return ansv;

    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Parser P1("input.ini");
    try {
        P1.read_file();
    }
    catch (std::logic_error& err) {
        std::cout << err.what();
        return 0;
    }

    int a = P1.get_value<int>("S1.var123");

    std::cout << a;

    return 0;
}
