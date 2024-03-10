#include <iostream>

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
    std::map<std::string, std::string> names;

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
                names[val_pair.first] = "int";
                int_vals[val_pair.first] = std::stoi(val_pair.second);
            }
            else if (dot == 1 && cifrs == val_pair.second.length() - 1) {
                names[val_pair.first] = "double";
                double_vals[val_pair.first] = std::stod(val_pair.second);
            }
            else {
                names[val_pair.first] = "string";
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
            std::cout << pair.second << ": " << pair.first << ", " << std::endl;
        }
    }

    template <class T>
    T get_val(std::string name) {
       
        T ansv;

        if constexpr (std::is_same_v<T, int>) { 
            if (!int_vals.count(name)) {
                throw std::invalid_argument("переменная " + name + " типа int не найдена");
            }
            ansv = int_vals[name];
        }
        else if constexpr (std::is_same_v<T, double>) { 
            if (!double_vals.count(name)) {
                throw std::invalid_argument("переменная " + name + " типа double не найдена");
            }
            ansv = double_vals[name]; 
        }
        else if constexpr (std::is_same_v<T, std::string>) { 
            if (!string_vals.count(name)) {
                throw std::invalid_argument("переменная " + name + " типа string не найдена");
            }
            ansv = string_vals[name];
        }

        return ansv;
    }
};

class Parser {
protected:
    std::map<std::string, std::unique_ptr<Section>> full;
    std::string kursor;
    std::string filename;

public:
    Parser(std::string filename_) : filename(filename_) {}

    void read_file() {
        std::ifstream input_file(filename);

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
                        if (pos == -1) {
                            throw std::logic_error("Неверный синтаксис в строке " + std::to_string(number_line));
                        }

                        vals[kursor.substr(0, pos)] = kursor.substr(pos + 1, kursor.find(";") - pos - 1);

                        if (vals[kursor.substr(0, pos)] == "") {
                            throw std::logic_error("Неверный синтаксис в строке " + std::to_string(number_line));
                        }
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
            throw std::logic_error("Файл не найден");
        }
    }

    void print_all() {

        for (const auto& pair : full) {
            std::cout << pair.first << std::endl;
            pair.second->print();
        }
    }

    template <class T>
    T get_value(std::string key) {
        std::string name_sec = key.substr(0, key.find('.'));
        std::string name_val = key.substr(key.find('.') + 1, key.length());

        if (full.empty()) {
            throw std::logic_error("Файл пустой или не был прочитан!");
        }

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

    Parser& operator=(const Parser& right) = delete;
    Parser(const Parser& right) = delete;

    Parser& operator=(Parser&& right) {
        if (&right == this) {
            return *this;
        }

        filename = right.filename;
        full = std::move(right.full);

        return *this;
    }
    Parser(Parser&& right) {
        filename = right.filename;
        full = std::move(right.full);
    }

    ~Parser() {}
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

    int a;
    std::string b;

    try {
        a = P1.get_value<int>("S1.var2");
        b = P1.get_value<std::string>("S1.var1");
    }
    catch (std::logic_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}
