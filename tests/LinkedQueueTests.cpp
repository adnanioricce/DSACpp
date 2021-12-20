#include "doctest.h"
#include <Share/LinkedQueue.h>
TEST_CASE("Enqueue and Dequeue tests") {
	LinkedQueue<int> list;
	for (int i = 0; i < 21; ++i) {
		list.Enqueue(i);
	}
	for (int i = 0; i < 21; ++i) {
		auto item = list.Dequeue();
		CHECK(i == item);
	}
}
TEST_CASE("Size return number of elements") {
	LinkedQueue<int> list;
	for (int i = 0; i < 21; ++i) {
		list.Enqueue(i);
	}
	CHECK(list.Size() == 21);
}