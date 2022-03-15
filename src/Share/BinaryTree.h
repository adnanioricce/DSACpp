#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <optional>

template<typename T>
class BinaryTree
{		
public:
	BinaryTree();
	~BinaryTree();
	void Insert(const T data);
	std::optional<T> Search(T data);
	std::optional<T> FindMinimum();
	std::optional<T> FindMaximum();
	void TraverseTree(void (*processItem)(T data));
	void Delete(const T data);

private:	
	struct Tree {
		T Data;
		Tree* Parent;
		Tree* Left;
		Tree* Right;
		Tree(T data, Tree* parent, Tree* left, Tree* right) {
			this->Data = data;
			this->Parent = parent;
			this->Left = left;
			this->Right = right;
		}
	};
	Tree* tree;
	void Insert(Tree** l,Tree* parent,const T data) {
		if ((*l) == nullptr) {
			Tree* p = new Tree(data, parent, nullptr, nullptr);
			(*l) = p;
			return;
		}
		if ((*l)->Data > data) {
			Insert(&(*l)->Left, (*l), data);
		}
		else {
			Insert(&(*l)->Right, (*l), data);
		}
	}
	std::optional<T> Search(const Tree* l, T data) {
		if (l == nullptr) {
			return std::nullopt;
		}
		if (l->Data == data) {
			return std::make_optional(data);
		}

		return l->Data > data
			? Search(l->Left, data)
			: Search(l->Right, data);		
	}
	void TraverseTree(const Tree* l, void (*processItem)(T data)) {
		if (l == nullptr)
			return;
		TraverseTree(l->Left, processItem);
		processItem(l->Data);
		TraverseTree(l->Right, processItem);
	}	
	Tree* FindMinimum(Tree *l) const {		
		if (l->Left == nullptr)
			return l;
		return FindMinimum(l->Left);
	}
	Tree* FindMaximum(Tree *l) const {
		if (l->Right == nullptr)
			return l;
		return FindMinimum(l->Right);
	}
	Tree* Delete(Tree **l,const T data) {		
		if ((*l) == nullptr)
			return (*l);
		if ((*l)->Data < data) {
			(*l)->Right = Delete(&((*l)->Right), data);
		}
		else if((*l)->Data > data) {
			(*l)->Left = Delete(&((*l)->Left), data);
		}
		else {
			if (((*l)->Left) == nullptr && ((*l)->Right) == nullptr) {
				(*l) = nullptr;
				return (*l);
			}
			else if ((*l)->Left == nullptr) {
				(*l) = (*l)->Right;				
			}
			else if ((*l)->Right == nullptr) {
				(*l) = (*l)->Left;				
			}
			else {
				Tree* temp = FindMinimum((*l)->Right);
				(*l)->Data = temp->Data;
				(*l)->Right = Delete(&(*l)->Right, temp->Data);

			}
		}
		return (*l);
	}
	void FreeBTree(Tree* t) {
		if (t == nullptr)
			return;
		FreeBTree(t->Left);
		FreeBTree(t->Right);

		delete t;
	}
};
template<typename T>
BinaryTree<T>::BinaryTree()
{	
	tree = nullptr;
}
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	FreeBTree(tree);
}
template<typename T>
void BinaryTree<T>::Insert(const T data) {	
	Tree** l = &tree;
	Insert(l, nullptr, data);
}
template<typename T>
void BinaryTree<T>::Delete(const T data) {
	Delete(&tree,data);
}
template<typename T>
std::optional<T> BinaryTree<T>::Search(T data) {	
	return Search(tree,data);
}
template<typename T>
std::optional<T> BinaryTree<T>::FindMinimum() {
	return FindMinimum(tree);
}
template<typename T>
std::optional<T> BinaryTree<T>::FindMaximum() {
	return FindMaximum(tree);
}
template<typename T>
void BinaryTree<T>::TraverseTree(void (*processItem)(T data)) {
	TraverseTree(tree, processItem);
}
#endif // !BINARYTREE_H