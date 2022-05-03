#pragma once
#ifndef HEAP_H
#define HEAP_H
#include <vector>
//TODO: Tests
class Heap
{
private:
	std::vector<int> heapList;
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
public:
	Heap();
	//~Heap();
	void Insert(int lement);
	bool DeleteMin();
	int ExtractMin();
	//void DisplayHeap();
	int Size();
	std::vector<int>::iterator GetIteratorBegin();
	std::vector<int>::iterator GetIteratorEnd();
};

Heap::Heap()
{	
}

//Heap::~Heap()
//{
//}
int Heap::Size() {
	return this->heapList.size();
}
void Heap::Insert(int element) {
	this->heapList.push_back(element);
	heapifyup(this->heapList.size() - 1);
}
bool Heap::DeleteMin() {
	if (this->heapList.size() == 0) {
		return false;
	}
	heapList[0] = heapList.at(heapList.size() - 1);
	heapList.pop_back();
	heapifydown(0);
	return true;
}
int Heap::ExtractMin() {
	if (heapList.size() == 0) {
		return -1;
	}
	return heapList.front();
}
int Heap::left(int parent) {
	int l = 2 * parent + 1;
	if (l < heapList.size()) {
		return l;
	}
	return -1;
}
int Heap::right(int parent) {
	int r = 2 * parent + 2;
	if (r < heapList.size()) {
		return r;
	}
	return -1;
}
int Heap::parent(int child) {
	int p = (child - 1) / 2;
	if (child == 0) {
		return -1;
	}
	return p;
}
void Heap::heapifyup(int in) {
	if (in < 0) {
		return;
	}
	if (parent(in) < 0) {
		return;
	}
	if (this->heapList[parent(in)] < heapList[in]) {
		return;
	}
	int temp = heapList[in];
	heapList[in] = heapList[parent(in)];
	heapList[parent(in)] = temp;
	heapifyup(parent(in));
}
void Heap::heapifydown(int in) {
	int childLeft = left(in);
	int childRight = right(in);
	if (childLeft >= 0 && childRight >= 0 && heapList[childLeft] > heapList[childRight]) {
		childLeft = childRight;
	}
	if (childLeft > 0) {
		int temp = heapList[in];
		heapList[in] = heapList[childLeft];
		heapList[childLeft] = temp;
		heapifydown(childLeft);
	}
}
std::vector<int>::iterator Heap::GetIteratorBegin() {
	return heapList.begin();
}
std::vector<int>::iterator Heap::GetIteratorEnd() {
	return heapList.end();
}
#endif