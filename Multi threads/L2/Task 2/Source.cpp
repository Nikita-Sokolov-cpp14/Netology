#include <vector>
#include <iostream>


int main() {
	std::vector<std::unique_ptr<std::ostream>> streamArray;

	for (int i = 0; i < 5; ++i) {
		streamArray.emplace_back(new std::ostream);
	}

	for (const auto& stream : streamArray) {
		stream << "Hello world! " << std::endl;
	}

	std::cout << "abc";

	return 0;
}