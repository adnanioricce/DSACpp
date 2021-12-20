#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iterator>
#include <iostream>
using namespace std;
template<typename T>
class Queue
{
private:
	int _maxSize = 10;
	int _currentIndex = 0;	
	T* _items;
	void Resize(){
		int newSize = (int)(_maxSize * 1.5);
		T* tempArr = new T[newSize];
		std::copy(_items, _items + _maxSize, tempArr);
		delete[] _items;
		_items = tempArr;
		_maxSize = newSize;
	}
public:
	Queue(){		
		_items = new T[_maxSize];
	}
	Queue(int size){
		_maxSize = size > _maxSize ? size : _maxSize;	
		_items = new T[size];
	}
	~Queue(){
		free(_items);
	}
	void Enqueue(T item){
		if(_currentIndex == _maxSize){
			Resize();
		}
		_items[this->_currentIndex] = item;
		_currentIndex++;
	}
	T Dequeue(){
		if(this->_currentIndex == 0)
			return _items[this->_currentIndex];
		auto item = _items[0];
		for (int i = 0; i < _currentIndex - 1; ++i) {
			_items[i] = _items[i + 1];
		}
		
		this->_currentIndex--;
		return item;
	}
	int Size(){
		return _currentIndex;
	}
	
};
//TODO:isso vai falhar pra uma struct, trata isso ou não?
template<typename T>
void Menu(const Queue<T> &queue) {
	cout << "i - Enqueue" << endl;
	cout << "r - Dequeue" << endl;
	cout << "c - Size" << endl;
	cout << "s - Stop" << endl;
	char opcao;
	cin >> opcao;	
	while (true) {
		if (opcao == 'i') {		
			cout << "Insert a item: " << endl;
			T value;
			cin >> value;
			queue.Enqueue(value);
			cout << "Inserted value: " << value << endl;
		}
		if (opcao == 'r') {
			cout << "Removed Item: " << queue.Dequeue() << endl;			
		}
		if (opcao == 'c') {
			cout << "Size: " << queue.Size() << endl;			
		}
		if (opcao == 's') {
			cout << "Stopping Queue menu ..." << endl;
			return;
		}
	}	
}
#endif