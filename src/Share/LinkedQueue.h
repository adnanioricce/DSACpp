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

//Eu decidi colocar isso aqui, porque eu considero que isso não faz realmente parte de uma fila,
//ter uma opção "Listar" em uma estrutura de fila, me parece quebrar o próprio conceito de fila(ela não parece mais uma fila, mas uma lista com outro nome),
//pois se você quiser listar os elementos de uma fila, utilize a própria interface da fila: enfileirando no fim e retirando do começo
template<typename T>
void ListarItems(LinkedQueue<T> queue) {
	auto item = queue.Dequeue();
	while (item.has_value())
	{
		std::cout << item.value() << std::endl;
		item = queue.Dequeue();
	}
}
template<typename T>
void Menu(LinkedQueue<T> queue) {	
	char opcao;
	bool _continuar = true;
	while (_continuar) {
		std::cout << "i - Push" << std::endl;
		std::cout << "r - Pop" << std::endl;
		std::cout << "s - Size" << std::endl;
		std::cout << "e - Stop" << std::endl;
		
		std::cin >> opcao;
		if (opcao == 'i') {
			T value;
			std::cin >> value;
			queue.Enqueue(value);
			std::cout << "Inserted value: " << value << std::endl;			
		}
		else if (opcao == 'r') {
			auto item = queue.Dequeue();
			if (!item.has_value()) {
				std::cout << "Queue is empty" << std::endl;
			}
			else {
				std::cout << "Removed Item: " << item.value() << std::endl;
			}			
		}
		else if (opcao == 'l') {
			ListarItems(queue);
		}
		else if (opcao == 's') {
			std::cout << "Size: " << queue.Size() << std::endl;			
		}
		else if (opcao == 'e') {
			_continuar = false;
		}
		else {
			return;
		}
	}
}
#endif // !LINKEDQUEUE_H
