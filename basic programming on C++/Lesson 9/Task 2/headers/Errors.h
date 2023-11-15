#pragma once
#include <iostream>
#include <string>

class creation_error : public std::domain_error {
private:
	const char* why;
public:
	const char* what() const override;
	creation_error(const char* why);
};