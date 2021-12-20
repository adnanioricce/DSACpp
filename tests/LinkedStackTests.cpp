#include "doctest.h"
#include <Share/LinkedStack.h>

TEST_CASE("Push and Pop Tests") {
	LinkedStack<int> stack;
	for (int i = 0; i < 10; ++i) {
		stack.Push(i);
	}
	for (int i = 9; i > 0; --i) {
		auto item = stack.Pop();
		CHECK(item.has_value());
		CHECK(i == item.value());
	}
}