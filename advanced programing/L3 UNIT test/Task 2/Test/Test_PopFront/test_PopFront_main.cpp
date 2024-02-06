#include <iostream>

#include "Headers/List.h"
#include "Headers/ListNode.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("PopFront", "(Test_1)") {
	List list;
	CHECK(list.PopFront() == 0);
}

int test_foo() {
	return Catch::Session().run();
}

int main() {
	int a = test_foo();
	system("pause");
	
	return a;
}