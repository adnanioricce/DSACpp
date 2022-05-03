#include <doctest/doctest.h>
#include <Share/RBTree.h>

TEST_CASE("Single insertion"){
	RBTree<int> tree;
	tree.Insert(10);
	auto searchOpt = tree.Search(10);
	CHECK(searchOpt.has_value());
}
TEST_CASE("Multiple insertions") {
	RBTree<int> tree;
	for (int i = 0; i < 10; i++) {
		tree.Insert(i * 2 + 3);
	}
	auto searchOpt = tree.Search(2 * 2 + 3);
	CHECK(searchOpt.has_value());
}
int c = 0;
void countTree(int key) {
	c++;
}
TEST_CASE("Test Height") {
	RBTree<int> tree;
	for (int i = 0; i < 10; i++) {
		tree.Insert(i * 2 + 3);
	}	
	tree.Traverse(countTree);
	CHECK(c == 10);
}