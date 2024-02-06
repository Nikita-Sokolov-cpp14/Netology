#include <iostream>

#include "Headers/List.h"
#include "Headers/ListNode.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Size", "(Test_1)") {
	List list;
	CHECK(list.Size() == 0);
	list.PushFront(1);
	CHECK(list.Size() == 1);
	list.PushBack(2);
	CHECK(list.Size() == 2);
	list.PopFront();
	CHECK(list.Size() == 1);
	list.PopBack();
	CHECK(list.Size() == 0);
	list.PushFront(10);
	list.PushFront(20);
	list.Clear();
	CHECK(list.Size() == 0);
}

int test_foo() {
	return Catch::Session().run();
}

int main() {
	int a = test_foo();
	system("pause");
	
	return a;
}