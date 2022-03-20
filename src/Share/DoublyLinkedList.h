#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <memory>
#include <optional>

template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void PrependNode(T data);
	void AppendNode(T data);
	std::optional<T> Search(T data);
	void DeleteNode(T data);
private:	
	struct DoubleNode
	{
		T Data;
		std::shared_ptr<DoubleNode> Next;
		std::shared_ptr<DoubleNode> Previous;
		DoubleNode() : Data(nullptr),Next(nullptr), Previous(nullptr) {			
		}
		DoubleNode(T data) : Data(data), Next(nullptr), Previous(nullptr)
		{
		}
		DoubleNode(T data, std::shared_ptr<DoubleNode> next, std::shared_ptr<DoubleNode> previous) : Data(data),Next(next), Previous(previous)
		{			
		}
	};
	std::shared_ptr<DoubleNode> head;
	std::shared_ptr<DoubleNode> tail;
	std::shared_ptr<DoubleNode> find(T data)
	{                            //returns node of the given value
		std::shared_ptr<DoubleNode> node = this->head;
		while (node != nullptr)
		{
			if (node->Data == data)
				return node;
			node = node->Next;
		}		
		return nullptr;
	}
};
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
}
template<typename T>
void DoublyLinkedList<T>::PrependNode(T data) {
	std::shared_ptr<DoubleNode> node = std::make_shared<DoubleNode>(data);
	std::shared_ptr<DoubleNode> tmp = this->head;
	if (this->head == nullptr) {
		this->head = node;
		this->tail = node;
	}
	else {
		node->Next = this->head;
		this->head = node;
		node->Next->Previous = node;
	}
}
template<typename T>
void DoublyLinkedList<T>::AppendNode(T data) {
	std::shared_ptr<DoubleNode> node = std::make_shared<DoubleNode>(data);
	if (tail->Next == nullptr) {
		tail->Next = node;
		tail = tail->Next;
	}
}
template<typename T>
void DoublyLinkedList<T>::DeleteNode(T data) {
	std::shared_ptr<DoubleNode> finded = find(data);
	std::shared_ptr<DoubleNode> tmp = head;
	if (finded == nullptr) {
		return;
	}
	if (tmp == finded) {
		head = tmp->Next;
		return;
	}
	while (finded != nullptr)
	{
		if (tmp->Next == finded) {
			tmp->Next = finded->Next;
			finded->Next->Previous = tmp;
			finded.reset();
			return;
		}
		tmp = tmp->Next;
	}
}
template<typename T>
std::optional<T> DoublyLinkedList<T>::Search(T data) {
	std::shared_ptr<DoubleNode> node = head;
	while (node != nullptr)
	{
		if (node->Data == data)
			return std::make_optional(data);
		node = node->Next;
	}
	return std::nullopt;
}



#endif // !DOUBLELINKEDLIST_H
