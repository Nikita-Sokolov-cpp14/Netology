#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction operator+(Fraction right) {
		int numerator = numerator_ * right.denominator_ + denominator_ * right.numerator_;
		int denominator = denominator_ * right.denominator_;
		return Fraction(numerator, denominator);
	}
	Fraction operator-(Fraction right) {
		int numerator = numerator_ * right.denominator_ - denominator_ * right.numerator_;
		int denominator = denominator_ * right.denominator_;
		return Fraction(numerator, denominator);
	}
	Fraction operator*(Fraction right) {
		return Fraction(numerator_ * right.numerator_, denominator_ * right.denominator_);
	}
	Fraction operator/(Fraction right) {
		int numerator = numerator_ * right.denominator_;
		int denominator = denominator_ * right.numerator_;
		return Fraction(numerator, denominator);
	}
	Fraction& operator++() {
		numerator_ += denominator_;
		return *this;
	}
	Fraction& operator++(int) {
		Fraction tmp(numerator_, denominator_);
		numerator_ += denominator_;
		return tmp;
	}
	Fraction& operator--() {
		numerator_ -= denominator_;
		return *this;
	}
	Fraction& operator--(int) {
		Fraction tmp(numerator_, denominator_);
		numerator_ -= denominator_;
		return tmp;
	}
	friend std::ostream& operator<<(std::ostream& left, Fraction right);
};
std::ostream& operator<<(std::ostream& left, Fraction right) {
	return (left << right.numerator_ << "/" << right.denominator_);
}
int main() {
	setlocale(LC_ALL, "Russian");

	int num_1, denom_1;
	int num_2, denom_2;
	std::cout << "Введите числитель дроби 1:";
	std::cin >> num_1;
	std::cout << "Введите знаменатель дроби 1:";
	std::cin >> denom_1;
	std::cout << "Введите числитель дроби 2:";
	std::cin >> num_2;
	std::cout << "Введите знаменатель дроби 2:";
	std::cin >> denom_2;
	Fraction f_1(num_1, denom_1), f_2(num_2, denom_2);
	std::cout << f_1 << " + " << f_2 << " = " << f_1 + f_2 << std::endl;
	std::cout << f_1 << " - " << f_2 << " = " << f_1 - f_2 << std::endl;
	std::cout << f_1 << " * " << f_2 << " = " << f_1 * f_2 << std::endl;
	std::cout << f_1 << " / " << f_2 << " = " << f_1 / f_2 << std::endl;
	std::cout << "++" << f_1 << " * " << f_2 << " = ";
	std::cout << ++f_1 * f_2 << std::endl;
	std::cout << "Значение дроби 1 = " << f_1 << std::endl;
	std::cout << f_1 << "--" << " * " << f_2 << " = ";
	std::cout << f_1-- * f_2 << std::endl;
	std::cout << "Значение дроби 1 = " << f_1 << std::endl;
	std::cout << "--" << f_1 << " * " << f_2 << " = ";
	std::cout << --f_1 * f_2 << std::endl;
	std::cout << "Значение дроби 1 = " << f_1 << std::endl;
	std::cout << f_1 << "++" << " * " << f_2 << " = ";
	std::cout << f_1++ * f_2 << std::endl;
	std::cout << "Значение дроби 1 = " << f_1 << std::endl;
	return 0;
}