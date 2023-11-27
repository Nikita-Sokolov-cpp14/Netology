#pragma once
#include <iostream>

#ifndef LEAVERLIB_EXPORTS
#define TRIG_LIB_API __declspec(dllimport)
#else
#define  TRIG_LIB_API __declspec(dllexport)
#endif

class Leaver {
public:
	TRIG_LIB_API std::string leave(std::string Name);
};