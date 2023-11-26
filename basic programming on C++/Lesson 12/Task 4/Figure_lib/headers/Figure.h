#pragma once
#include <string>
#include <iostream>

#ifndef DINAMIC_EXPORTS
#define TRIG_LIB_API __declspec(dllexport)
#else
#define TRIG_LIB_API __declspec(dllimport)
#endif

class Figure {
protected:
    std::string type;
public:
    TRIG_LIB_API virtual void print_figure();
};