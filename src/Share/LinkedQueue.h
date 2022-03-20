#pragma once
#ifndef LINKEDQUEUE_H
//#include "LinkedList.h"
#include <optional>

using namespace std;
template<typename T>
class LinkedQueue
{
private:
	struct Node
	{
		T Data;
		Node *Next;
	} *head = NULL, *tail = NULL, *pointer = NULL;
	int count = 0;	
public:
	LinkedQueue()
	{
	}

	~LinkedQueue()
	{
	}

	void Enqueue(T item) {
		pointer = (Node*)malloc(sizeof(this->pointer));
		pointer->Data = item;
		pointer->Next = NULL;
		if (head == NULL) {
			head = pointer;
		}
		else {
			tail->Next = pointer;
		}
		tail = pointer;
		count++;
	}

	optional<T> Dequeue() {
		if (head == NULL)
			return std::nullopt;
		auto item = head->Data;
		auto previous = head;
		head = head->Next;		
		return std::make_optional(item);
	}
	int Size() {
		return count;
	}

};
#endif // !LINKEDQUEUE_H
