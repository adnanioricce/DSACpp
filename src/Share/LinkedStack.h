#pragma once
#ifndef LINKEDSTACK_H
#include "LinkedList.h"
#include <optional>
#include <iostream>
using namespace std;
//TODO:Reuse LinkedList instead of create a new Node struct
template<typename T>
class LinkedStack
{
private:
	LinkedList<T> list;
public:
	LinkedStack()
	{
	}

	~LinkedStack()
	{		
	}
	void Push(T item) {
		list.InsertAtStart(item);
		/*AppendAtStart(&head, item);
		count++;*/
	}
	std::optional<T> Pop() {
		/*if (head == NULL)
			return std::nullopt;
		auto data = head->Data;
		auto previous = head;
		head = head->Next;
		free(previous);*/
		auto tail = list.GetIteratorFromTail();
		auto dataOpt = tail.GetCurrent();
		if(dataOpt.has_value())
			list.Delete(dataOpt.value());
		return dataOpt;
		//return std::make_optional(data);
	}
	int Size() {
		return count;
	}
};
template<typename T>
void ListarItems(LinkedStack<T> stack) {
	auto item = stack.Pop();
	while (item.has_value())
	{
		std::cout << item.value() << std::endl;
		item = stack.Pop();
	}
}
template<typename T>
void Menu(LinkedStack<T> stack) {
	char opcao;	
	while (true) {
		cout << "i - Push" << endl;
		cout << "r - Pop" << endl;
		cout << "s - Size" << endl;
		cout << "e - Stop" << endl;

		cin >> opcao;
		if (opcao == 'i') {
			T value;
			cin >> value;
			stack.Push(value);
			cout << "Inserted value: " << value << endl;
		}
		else if (opcao == 'r') {
			auto item = stack.Dequeue();
			if (!item.has_value()) {
				cout << "Queue is empty" << endl;
			}
			else {
				cout << "Removed Item: " << item.value() << endl;
			}
		}
		else if (opcao == 'l') {
			ListarItems(stack);
		}
		else if (opcao == 's') {
			cout << "Size: " << stack.Size() << endl;
		}		
		else {
			return;
		}
	}
}
#endif // !LINKEDSTACK_H
