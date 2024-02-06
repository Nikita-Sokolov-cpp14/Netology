#include <iostream>

#include "Headers/List.h"
#include "Headers/ListNode.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Clear", "(Test_1)") {
	List list;
	list.Clear();
	CHECK(list.Empty() == true);
	list.PushFront(1);
	list.PushBack(2);
	list.PushFront(10);
	list.PushFront(20);
	list.Clear();
	CHECK(list.Empty() == true);
}

int test_foo() {
	return Catch::Session().run();
}

int main() {
	int a = test_foo();
	system("pause");
	
	return a;
}