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
                int_vals[val_pair.first] = std::stoi(val_pair.second);
            }
            else if (dot == 1 && cifrs == val_pair.second.length() - 1) {
                double_vals[val_pair.first] = std::stod(val_pair.second);
            }
            else {
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

    template <class T>
    T get_val(std::string name) {

        std::cout << this->int_vals.empty() << std::endl;

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
    std::map<std::string, std::map<std::string, std::string>> full_2;
    std::ifstream input_file;
    std::string kursor;

public:
    Parser(std::string filename) {

        input_file.open(filename);

        if (input_file.is_open()) {

            std::map<std::string, int> count_name_section;
            std::string sec_name = "";

            bool flag = 1;

            while (!input_file.eof()) {
                std::map<std::string, std::string> vals;

                if (flag) {
                    std::getline(input_file, kursor, '\n');
                }

                if (kursor[0] == '[') {
                    int i = 1;
                    while (kursor[i] != ']') {
                        sec_name += kursor[i];
                        i++;
                    }
                    flag = 1;
                    continue;
                }

                while (kursor[0] != '[') {

                    if (!flag) {
                        std::getline(input_file, kursor, '\n');
                    }
                    

                    if (kursor[0] != '[' && kursor[0] != ';' && kursor[0] != '\n') {
                        int pos = kursor.find("=");
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

                        full_2[sec_name] = vals;

                        //full[sec_name] = std::make_unique<Section>();
                        //full[sec_name]->set_vals(vals);
                    }
                    else {
                        for (const auto& pair : vals) {
                            full_2[sec_name][pair.first] = pair.second;
                        }

                        //full[sec_name]->set_vals(vals);
                    }
                }
                sec_name = "";
            }
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

        T ansv = full[name_sec]->get_val<T>(name_val);

        return ansv;

    }

    template <class T>
    T get_value_2(std::string key) {
        std::string name_sec = key.substr(0, key.find('.'));
        std::string name_val = key.substr(key.find('.') + 1, key.length());

        std::string value = full_2[name_sec][name_val];

        std::cout << value << std::endl;

        T ansv;

        int cifrs = 0;
        int dot = 0;

        for (const auto& symb : value) {
            if (static_cast<int>(symb) >= static_cast<int>('0') && static_cast<int>(symb) <= static_cast<int>('9')) {
                cifrs++;
            }
            if (static_cast<int>(symb) == static_cast<int>('.')) {
                dot++;
            }
        }

        if (cifrs == value.length()) {
            if constexpr(std::is_same_v<T, int>) { ansv = std::stoi(value); }
        }
        else if (dot == 1 && cifrs == value.length() - 1) {
            if constexpr(std::is_same_v<T, double>) { ansv = std::stod(value); }
        }
        else {
            if constexpr(std::is_same_v<T, std::string>) { ansv = value; }
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

    //P1.print();

    //P1.get_value<int>("s1.var1");

    //int a = P1.get_value<int>("s1.var1");

    int a = P1.get_value_2<int>("S1.var1");

    std::cout << a;

    return 0;
}
