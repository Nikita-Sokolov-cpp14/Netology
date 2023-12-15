#include <iostream>

int Fibonachi(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		int a_last, a_last_last, a;
		a_last = n - 1;
		a_last_last = n - 2;
		a = Fibonachi(a_last) + Fibonachi(a_last_last);
		return a;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	int N = 0;
	int a_N = 0;

	std::cout << "Ведите номер искомого числа Фибоначи: ";
	std::cin >> N;

	a_N = Fibonachi(N);

	std::cout << "Член последовательности ФИбоначи с номером " << N << " = " << a_N << std::endl;

	return 0;
}