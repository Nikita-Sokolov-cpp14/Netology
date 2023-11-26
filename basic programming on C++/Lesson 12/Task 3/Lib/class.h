#pragma once

#include <iostream>
#include <string>

#ifndef DINAMICLIB_EXPORTS
#define  TRIG_LIB_API __declspec(dllexport)
#else
#define TRIG_LIB_API __declspec(dllimport)
#endif

class Leaver {
public:
	TRIG_LIB_API std::string leave(std::string Name);
};