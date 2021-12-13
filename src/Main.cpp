#include <iostream>
#include "Share/Queue.h"
#include "Share/Stack.h"
#include "Share/LinkedList.h"
using namespace std;
void TestQueue() {
	std::cout << "Testing queue" << std::endl;
	Queue<int> queue(20);
	for (int i = 50; i > 0; --i) {
		queue.Enqueue(i * 2);
	}
	std::cout << "Queue size: " << queue.Size() << std::endl;
	while (queue.Size() > 0)
	{
		cout << "Dequeue:" << queue.Dequeue() << std::endl;
	}
}
void TestStack() {
	std::cout << "Testing stack " << std::endl;
	Stack<int> stack;
	for (int i = 0; i < 20; ++i) {
		stack.Push(i);
	}
	std::cout << "Stack size " << stack.Size() << std::endl;
	while (stack.Size() > 0)
	{
		std::cout << stack.Pop() << std::endl;
	}
}
void TestList() {
	std::cout << "Testing list " << std::endl;
	LinkedList<int> list;
	for (int i = 1; i <= 5; ++i) {
		list.Insert(i);
	}
	std::cout << "Searching..." << std::endl;
	auto node = list.Search(4);
	auto value = node->Item;
	std::cout << "Element searched " << value << std::endl;
	list.Delete(value);
	auto isDeleted = list.Search(value);
	if (!isDeleted) {
		std::cout << value << " was deleted " << std::endl;
	}
	else {
		std::cout << "Node was not deleted" << std::endl;
	}
}
int main(){
	TestQueue();
	TestStack();
	TestList();
	return 0;
}      