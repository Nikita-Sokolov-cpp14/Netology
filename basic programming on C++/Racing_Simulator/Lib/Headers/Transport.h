#pragma once
#include <iostream>

class Transport {
protected:
    int speed;
    int distance;
    double full_time = 0;
    std::string name;
public:
    double get_time();
    virtual void calc_time();
    bool operator>(Transport right);
    std::string get_name();
};
