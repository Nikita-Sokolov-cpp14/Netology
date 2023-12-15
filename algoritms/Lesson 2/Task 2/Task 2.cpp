#include <iostream>

int Fibonachi(int a_last, int a, int N) {
	if (N > 1) {
		return Fibonachi(a, a_last + a, --N);
	}
	else {
		return a;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int a_last = 0;
	int a = 1;
	int N = 0;
	int a_N = 0;

	std::cout << "Ведите номер искомого числа Фибоначи: ";
	std::cin >> N;

	a_N = Fibonachi(a_last, a, N);

	std::cout << "Член последовательности ФИбоначи с номером " << N << " = " << a_N << std::endl;

	return 0;
}
