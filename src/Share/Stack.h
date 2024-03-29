#pragma once
#ifndef STACK_H
#define STACK_H
#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>
using namespace std;
template<class T>
class Stack
{
public:
	Stack(){
		_items = new T[_maxSize];
	}
	~Stack(){
		free(_items);
	}
	void Push(T item){		
		if(_currentIndex == _maxSize){
			Resize();
		}
		_items[_currentIndex] = item;
		_currentIndex++;		
	}
	T Pop(){
		if(_currentIndex == 0)
			return _items[_currentIndex];
		_currentIndex--;
		auto removedItem = _items[_currentIndex];		
		return removedItem;
	}
	int Size() {
		return _currentIndex;
	}
private:
	void Resize(){		
		size_t newSize = (size_t)(_maxSize * 1.5);
		T* tempArr = new T[newSize];
		//memcpy(tempArr, _items, _maxSize);
		std::copy(_items, _items + _maxSize, tempArr);
		delete[] _items;
		_items = tempArr;
		_maxSize = newSize;
	}
	T* _items;
	size_t _maxSize = 10;
	size_t _currentIndex = 0;
	size_t _currentSize = 0;
};
template<typename T>
void Menu(Stack<T> stack) {
  cout << "i - Push" << endl;
  cout << "r - Pop" << endl;
  cout << "c - Size" << endl;
  cout << "s - Stop" << endl;
  char opcao;
  cin >> opcao;  
  while(true){
	if (opcao == 'i') {
		cout << "Insert a value " << endl;
		T value;
		cin >> value;
		stack.Push(value);
		cout << "Inserted value: " << value << endl;
	}
	if (opcao == 'r') {
		cout << "Removed Item: " << stack.Pop() << endl;
	}
	if(opcao == 'c'){
		cout << "Count number of elements " << stack.Size() << endl;
	}
	if (opcao == 's') {		
		cout << "Stopping stack menu ..." << endl;
		return;
	}
  }
}
#endif // !STACK_H
