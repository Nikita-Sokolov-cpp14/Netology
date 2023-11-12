#pragma once
#include <string>
#include <iostream>

class Counter {
private:
    int count;
public:
    Counter();
    void set_count(int count);
    void step(char comand);
};