#include <iostream>

#include "Headers/List.h"
#include "Headers/ListNode.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("PushFront", "(Test_1)") {
	List list;
	list.PushFront(10);
	CHECK(list.Size() == 1);
	list.PushFront(20);
	list.PushFront(30);
	CHECK(list.PopFront() == 30);
}

int test_foo() {
	return Catch::Session().run();
}

int main() {
	int a = test_foo();
	system("pause");
	
	return a;
}