#include <doctest/doctest.h>
#include <Share/Heap.h>
#include <cstdlib>
#include <vector>
#include <array>
#include <iostream>
void DisplayHeap(Heap &heap){
	std::vector<int>::iterator pos = heap.GetIteratorBegin();
	std::cout << "Heap -->  ";
	while (pos != heap.GetIteratorEnd())
	{
		std::cout << *pos << " ";
		pos++;
	}
	std::cout << std::endl;
}
std::array<int, 10> arr = { 57, 1,9, -24, 7, 1, 22, -2, 2, -23 };
TEST_CASE("test insert") {
	Heap heap;		
	for (size_t i = 0; i < 10; i++)
	{		
		heap.Insert(arr[i]);
	}
	CHECK(heap.Size() == 10);	
}
TEST_CASE("Test Heap::ExtractMin") {
	Heap heap;
	//std::vector<int> numbers = {};	
	for (size_t i = 0; i < 10; i++)
	{				
		heap.Insert(arr[i]);
	}
	CHECK(-24 == heap.ExtractMin());
}
TEST_CASE("See Heap on console") {
	Heap heap;		
	for (size_t i = 0; i < 10; i++)
	{
		heap.Insert(arr[i]);
	}
	DisplayHeap(heap);
}
//TEST_CASE("Test")