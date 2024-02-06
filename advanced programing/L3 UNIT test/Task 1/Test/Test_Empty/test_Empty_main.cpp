#include <iostream>

#include "Headers/List.h"
#include "Headers/ListNode.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Empty", "(Test_1)") {
	List list;
	CHECK(list.Empty() == true);
	list.PushFront(1);
	CHECK(list.Empty() == false);
	list.PushBack(2);
	CHECK(list.Empty() == false);
	list.PopFront();
	CHECK(list.Empty() == false);
	list.PopBack();
	CHECK(list.Empty() == true);
	list.PushFront(10);
	list.PushFront(20);
	list.PushFront(30);
	list.PushFront(40);
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