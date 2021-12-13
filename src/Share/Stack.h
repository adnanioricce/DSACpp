#pragma once
#ifndef STACK_H
#define STACK_H
#include <algorithm>
#include <array>
#include <iterator>
template<class T>
class Stack
{
public:
	Stack(){
		_items = new T[_maxSize];
	}
	~Stack(){
		delete _items;
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
	std::cout << "i - Push" << std::endl;
	std::cout << "r - Pop" << std::endl;
	std::cout << "s - Size" << std::endl;
	char opcao;
	opcao >> std::cin;
	if (opcao == 'i') {
		T value;
		value >> std::cin;
		stack.Push(value);
		return;
	}
	if (opcao == 'r') {
		std::cout << "Removed Item: " << stack.Pop() << std::endl;
		return;
	}
	if (opcao == 's') {
		std::cout << "Size: " << stack.Size() << std::endl;
		return;
	}
}
#endif // !STACK_H
