#include <iostream>

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <windows.h>


class Section {
protected:
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
    operator std::map<std::string, T>() const {
        if (typeid(T) == typeid(int)) { return &int_vals; }
        else if (typeid(T) == typeid(double)) { return &double_vals; }
        else if (typeid(T) == typeid(std::string)) { return &string_vals; }
    }
    

    //вариант 2
    /*
    template<class T>
    T get_val(std::string name) {
        if (typeid(T) == typeid(int)) { return int_vals[name]; }
        else if (typeid(T) == typeid(double)) { return double_vals[name]; }
        else if (typeid(T) == typeid(std::string)) { return string_vals[name]; }
    }
    */

    //вариант 3
    //void get_val(std::string name, int& val) { val = int_vals[name]; }
    //void get_val(std::string name, double& val) { val = double_vals[name]; }
    //void get_val(std::string name, std::string& val) { val = string_vals[name]; }
};

class Parser {
protected:
    std::map<std::string, std::unique_ptr<Section>> full;
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

                        full[sec_name] = std::make_unique<Section>();
                        full[sec_name]->set_vals(vals);
                    }
                    else {
                        full[sec_name]->set_vals(vals);
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


        auto vals = static_cast<std::map<std::string, T>>(*full[name_sec]);
        T ansv = vals[name_val];

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

    int a = P1.get_value<int>("s1.var1");

    return 0;
}
