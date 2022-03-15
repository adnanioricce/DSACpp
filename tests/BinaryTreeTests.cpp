#include <doctest/doctest.h>
#include <Share/BinaryTree.h>
#include <cstdlib>
#include <vector>
int counter = 0;
void processItem(int data) {
	counter++;
}
TEST_CASE("Insert Test") {

	BinaryTree<int> btree;
	btree.Insert(5);
	CHECK(btree.Search(5).has_value());
}
TEST_CASE("Traverse Test") {
	BinaryTree<int> btree;
	btree.Insert(5);
	btree.TraverseTree(processItem);
	CHECK(counter == 1);
}
TEST_CASE("Delete Item") {
	BinaryTree<int> btree;
	std::vector<int> numbers;
	for (int i = 0; i < 20;++i) {
		auto n = rand() % 324789;
		numbers.push_back(n);	
		btree.Insert(n);
	}	
	for (int i = 0; i < 10; i++) {
		int index = rand() % 20;
		int n = numbers[index];		
		btree.Delete(n);		
		auto t = btree.Search(n);
		CHECK(!t.has_value());
	}	
}
TEST_CASE("Test deallocation") {
	BinaryTree<int>* pointer = nullptr; {
		BinaryTree<int> btree;
		for (size_t i = 0; i < 6; i++)
		{
			int c = rand() / 356789;
			btree.Insert(c);
		}
		pointer = &btree;
	}
	CHECK(pointer);
}