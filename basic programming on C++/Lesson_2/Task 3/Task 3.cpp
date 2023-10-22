#include <iostream>
#include <string>

struct adress
{
	std::string city;
	std::string street;
	int number_hous;
	int number_appart;
	int index;
};

void print_adress(adress* A)
{
	std::cout << "Город: " << A->city << std::endl;
	std::cout << "Улица: " << A->street << std::endl;
	std::cout << "Номер дома: " << A->number_hous << std::endl;
	std::cout << "Номер квартиры: " << A->number_appart << std::endl;
	std::cout << "Индекс: " << A->index << std::endl;
}

int main()
{
	setlocale(LC_ALL, "russian");
	adress A1;
	A1.city = "Москва";
	A1.street = "Беломорская";
	A1.number_hous = 321;
	A1.number_appart = 1;
	A1.index = 123210;

	adress A2;
	A2.city = "Воркута";
	A2.street = "Московская";
	A2.number_hous = 1;
	A2.number_appart = 1;
	A2.index = 987654;

	print_adress(&A1);
	std::cout << "\n";
	print_adress(&A2);
	return 0;
}
