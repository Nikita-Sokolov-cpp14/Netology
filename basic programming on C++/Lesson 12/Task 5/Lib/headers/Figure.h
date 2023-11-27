#pragma once
#include <string>
#include <iostream>


class Figure {
protected:
    std::string type;
public:
    virtual void print_figure();
};