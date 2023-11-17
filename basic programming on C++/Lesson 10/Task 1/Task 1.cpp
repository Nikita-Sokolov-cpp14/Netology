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
	bool operator==(Fraction right) {
	//из приведения дробей к общему значенателю следует
		int num_1 = numerator_ * right.denominator_;
		int num_2 = right.numerator_ * denominator_;
		return num_1 == num_2;
	}
	bool operator<(Fraction right) {
		int num_1 = numerator_ * right.denominator_;
		int num_2 = right.numerator_ * denominator_;
		return num_1 < num_2;
	}
};

int main()
{
	Fraction f1(4, 6);
	Fraction f2(1, 2);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << (!(f1 == f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f2 < f1) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << (!(f2 < f1) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << (!(f1 < f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}