#include <iostream>

#include <map>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <fstream>
#include <windows.h>


class Section {
private:
    std::string name;
    std::map<std::string, int> int_vals;
    std::map<std::string, double> double_vals;
    std::map<std::string, std::string> string_vals;
public:
    Section(std::map<std::string, std::string> init, std::string name_) : name(name_) {
        
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
};

class Parser {
protected:
    std::unordered_map<std::string, std::map<std::string, std::string> > full;
    std::ifstream input_file;
    std::string kursor;

public:
    Parser(std::string filename) {

        input_file.open(filename);

        if (input_file.is_open()) {
           
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

                    auto it = full.find(sec_name);
                    if (it == full.end()) {
                        full[sec_name] = vals;
                    }
                    else {
                        for (const auto& value : vals) {
                            full[sec_name][value.first] = value.second;
                        }
                    }
                }
                sec_name = "";
            }
        }
    }

    ~Parser() {
        input_file.close();
    }

    template <class T>
    T get_value(std::string key) {

        std::string sec_name = key.substr(0, key.find("."));
        std::string val_name = key.substr(key.find(".") + 1, key.length() - 1);

        std::string val = full[sec_name][val_name];
        std::string type = "string";


        std::cout << full[sec_name]["var1"] << std::endl;
        std::cout << sec_name << " " << val_name << " " << val << std::endl;

        int cifrs = 0;
        int dot = 0;

        for (const auto& symb : val) {
            if (static_cast<int>(symb) >= static_cast<int>('0') && static_cast<int>(symb) <= static_cast<int>('9')) {
                cifrs++;
            }
            if (static_cast<int>(symb) == static_cast<int>('.')) {
                dot++;
            }
        }

        if (cifrs == val.length()) {
            int a = std::stoi(val);
        }
        else if (dot == 1 && cifrs == val.length() - 1) {
            double b = std::stod(val);
        }
        else {
            std::string c = val;
        }

        return 1;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Parser P1("input.ini");

    P1.get_value<int>("s1.var1");

    return 0;
}