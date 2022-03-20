#pragma once
#ifndef RBTREE_H
#define RBTREE_H
#include <memory>
#include <optional>
#define MAX(a,b) (((a)>(b))?(a):(b))
template<typename T>
class RBTree
{
public:
	RBTree();
	~RBTree();
	void Insert(T key);
  std::optional<T> Search(T key);
  bool Delete(T key);
  void Traverse(void (*processItem)(T key));

private:
  RBNode T_Nil_Node;
  RBNode* T_Nil = &T_Nil_Node;
  RBNode* Root = NULL;
	enum Color
	{
		Red,
		Black
	};
	struct RBNode
	{
		T key;
		Color color;
		struct RBNode* left;
		struct RBNode* right;
		struct RBNode* parent;
		RBNode(T key) {
			this->key = key;
			this->color = Color.Red;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}
	};
  
  void rotateLeft(RBNode** t,RBNode* x){
      RBNode *y = x->right;
      x->right = y->left;
      if(y->left != T_Nil)
          y->left->parent = x;
      y->parent = x->parent;
      if(x->parent == T_Nil)
          *t = y;
      else if(x == x->parent->left)
          x->parent->left = y;
      else
          x->parent->right = y;

      y->left = x;
      x->parent = y;
  }      
  void rotateRight(RBNode** t,RBNode* y)
  {
      RBNode *x = y->left;
      y->left = x->right;
      if(x->right != T_Nil)
          x->right->parent = y;

      x->parent = y->parent;
      if(y->parent == T_Nil)
          *t = x;
      else if(y == y->parent->right)
          y->parent->right = x;
      else
          y->parent->left = x;
      x->right = y;
      y->parent = x;
  }

void redBlackInsertFixup(RBNode** Root,RBNode* New)
{
    RBNode* temp;
    while(New->parent->color == Color.Red){
        if(New->parent == New->parent->parent->left){
            temp = New->parent->parent->right;
            if(temp->color == Color.Red){
                New->parent->color = Color.Black;
                temp->color = Color.Black;
                New->parent->parent->color = Color.Red;
                New = New->parent->parent;
            }
            else{
                if(New == New->parent->right){
                    New = New->parent;
                    rotateLeft(Root, New);
                }
                New->parent->color = Color.Black;
                New->parent->parent->color = Color.Red;
                rotateRight(Root, New->parent->parent);
            }
        }
        else {
            temp = New->parent->parent->left;
            if(temp->color == Color.Red){
                New->parent->color = Color.Black;
                New->color = Color.Black;
                New->parent->parent->color = Color.Red;
                New = New->parent->parent;
            }
            else{
                if(New == New->parent->left){
                    New = New->parent;
                    rotateRight(Root, New);
                }
                New->parent->color = Color.Black;
                New->parent->parent->color = Color.Red;
                rotateLeft(Root, New->parent->parent);
            }
        }
    }
    Root[0]->color = Color.Black;
}

void redBlackInsert(Node** T,int key){
    Node* z = newNode(key);
    Node* y = T_Nil;
    Node* x = *T;
    
    while(x != T_Nil){
        y = x;
        if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if(y == T_Nil)
        *T = z;
    else if(z->key < y->key)
        y->left = z;
    else
        y->right = z;

    //Init z as a red leaf
    z->left = T_Nil;
    z->right = T_Nil;
    z->color = RED;

    // Ensure the Red-Black property is maintained
    redBlackInsertFixup(T,z);
}

int height(Node* Root){
    int h = 0;
    if(Root == NULL)
      return;
    //if(Root != NULL){
        if(Root == T_Nil)
            h = 1;
        else {
            int leftHeight = height(Root->left);
            int rightHeight = height(Root->right);
            h = MAX(leftHeight, rightHeight) + 1;
        }
    //}
}
};
template<typename T>
RBTree<T>::RBTree()
{
}
template<typename T>
RBTree<T>::~RBTree()
{
}
template<typename T>
void RBTree<T>::Insert(T key){
}
template<typename T>
bool RBTree<T>::Delete(T key){
  return false;
}
template<typename T>
std::optional<T> RBTree<T>::Search(T key){
  return std::nullopt;
}
template<typename T>
void RBTree<T>::Traverse(void (*processItem)(T key)){

}
#endif // !RBTREE_H
