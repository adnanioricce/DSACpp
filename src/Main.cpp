#include <iostream>
#include "Share/Queue.h"
#include "Share/Stack.h"
#include "Share/LinkedList.h"
#include "Share/LinkedQueue.h"
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
	auto itemOpt = list.Search(4);	
	auto value = itemOpt.value();
	std::cout << "Element searched " << value << std::endl;
	;	
	if (!list.Delete(value)) {
		std::cout << "Node was not deleted" << std::endl;
	}
	else {		
		std::cout << value << " was deleted " << std::endl;
	}
}
void TestLinkedQueue() {
	LinkedQueue<int> queue;
	Menu(queue);
}

int main(){
	//ExemploBubbleSort();
	LinkedList<int> list;
	Menu(list);
	/*TestQueue();
	TestStack();
	TestList();
	TestLinkedQueue();*/
	return 0;
}      