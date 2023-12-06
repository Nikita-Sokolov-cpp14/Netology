#pragma once
#include <iostream>

#ifndef Racing_lib_EXPORTS
#define TRIG_LIB_API __declspec(dllimport)
#else
#define TRIG_LIB_API __declspec(dllexport)
#endif

class Racing {
protected:
    std::string type_of_racing;
    std::string name;
    double time;
    int number_drivers;
public:
    TRIG_LIB_API void init(int switcher, int dist);
    TRIG_LIB_API bool operator>(Racing right);
    TRIG_LIB_API friend std::ostream& operator<<(std::ostream& left, Racing right);
};
