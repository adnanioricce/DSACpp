#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#define DEFAULT_HASH_SIZE 100
#include <string>
#include <array>
//#include <memory>
//TODO: Move to a hash namespace
unsigned int hashCode(std::string key) {
	unsigned long hash = 5381;
	for each (auto ch in key)
	{
		//hash * 33  + c
		hash = ((hash << 5) + hash) + ch;
	}
	return hash % DEFAULT_HASH_SIZE;
}
template<typename T>
struct HashNode
{	
	//TODO: How to make this generic?
	std::string Key;
	T Data;
	struct HashNode *Next;
	HashNode() {
		this->Key = nullptr;
		this->Data = nullptr;
		this->Next = nullptr;
	}
	HashNode(std::string key,T data,struct HashNode* next) {
		this->Key = key;
		this->Data = data;
		this->Next = next;
	}
};
template<typename T>
class HashTable
{
public:
	HashTable();
	HashTable(int size);
	~HashTable();
	void Set(std::string key, T value);
	T Get(std::string key);

private:	
	std::array<HashNode<T>*, DEFAULT_HASH_SIZE> _list = {};	
	
};
template<typename T>
HashTable<T>::HashTable()
{
	//_list = new HashNode<T>[_size];
}
template<typename T>
HashTable<T>::HashTable(int size)
{
	//_size = size;
	//_list = new HashNode<T>[_size];
}
template<typename T>
HashTable<T>::~HashTable()
{
	
}
template<typename T>
void HashTable<T>::Set(std::string key, T value) {
	unsigned int index = hashCode(key);
	struct HashNode<T>* node = _list[index];
	if (node == nullptr) {
		_list[index] = new HashNode<T>(key, value, nullptr);
	}
	else {
		while (node != nullptr)
		{
			if (node->Next == NULL) {
				node->Next = new HashNode<T>(key, value, nullptr);
				break;
			}
			node = node->Next;
		}
	}
}
template<typename T>
T HashTable<T>::Get(std::string key) {
	unsigned int index = hashCode(key);
	struct HashNode<T>* node = _list[index];
	while (node != nullptr)
	{
		if (node->Key == key)
			return node->Data;
		node = node->Next;
	}
}
#endif // !HASHTABLE_H
