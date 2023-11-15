#pragma once
#include <string>
#include <iostream>
#include "Errors.h"

class Figure {
protected:
    std::string type;
public:
    virtual void print_figure();
};