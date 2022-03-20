#include <doctest/doctest.h>
#include <Share/DoublyLinkedList.h>

TEST_CASE("Main test") {
	DoublyLinkedList<int> list;
	list.PrependNode(3);
	list.AppendNode(5);
	list.AppendNode(12);
	list.PrependNode(6);
	list.AppendNode(88);	
	list.DeleteNode(11);
	list.DeleteNode(6);
	CHECK(list.Search(12).has_value());
	CHECK(!list.Search(6).has_value());
}