#include <doctest/doctest.h>
#include <Share/HashTable.h>
TEST_CASE("insert") {
	HashTable<int> htable;
	htable.Set("Test", 24);
	htable.Set("Test", 25);
	CHECK(htable.Get("Test") == 24);
}