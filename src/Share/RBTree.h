#pragma once
#ifndef RBTREE_H
#define RBTREE_H
#include <memory>
template<typename T>
class RBTree
{
public:
	RBTree();
	~RBTree();
	void Insert(T item);
private:
	enum Color
	{
		Red,
		Black
	};
	struct RBNode
	{
		T Key;
		Color color;
		std::shared_ptr<RBNode> left;
		std::shared_ptr<RBNode> right;
		std::shared_ptr<RBNode> parent;
		RBNode(T key) {
			this->Key = key;
			this->color = Color.Red;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}		
	};
};
template<typename T>
RBTree<T>::RBTree()
{
}
template<typename T>
RBTree<T>::~RBTree()
{
}
#endif // !RBTREE_H
