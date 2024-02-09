#include <iostream>

#include "List.h"

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("Test_list", "(Test_1)") {
	SECTION("Testing PopBack") {
		List list;
		INFO("List is empty! PopBack must throw exception!");
		REQUIRE_THROWS(list.PopBack());
	}
	SECTION("Testing PopFront") {
		List list;
		INFO("List is empty! PopBack must throw exception!");
		REQUIRE_THROWS(list.PopFront());
	}
	SECTION("Testing PushBack") {
		List list;
		list.PushBack(10);
		INFO("1 elem in list, but list.size() != 1");
		CHECK(list.Size() == 1);
		list.PushBack(20);
		list.PushBack(30);
		INFO("3 elem in list, but list.size() != 3");
		CHECK(list.Size() == 3);
	}
	SECTION("Testing PushFront") {
		List list;
		list.PushFront(10);
		INFO("1 elem in list, but list.size() != 3");
		CHECK(list.Size() == 1);
		list.PushFront(20);
		list.PushFront(30);
		INFO("3 elem in list, but list.size() != 3");
		CHECK(list.Size() == 3);
	}
	
}

int main() {
	return Catch::Session().run();
}