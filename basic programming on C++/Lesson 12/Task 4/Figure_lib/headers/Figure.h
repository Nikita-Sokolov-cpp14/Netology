#pragma once
#include <string>
#include <iostream>

#ifndef FIGURELIB_EXPORTS
#define TRIG_LIB_API __declspec(dllimport)
#else
#define TRIG_LIB_API __declspec(dllexport)
#endif

class Figure {
protected:
    std::string type;
public:
    TRIG_LIB_API virtual void print_figure();
};