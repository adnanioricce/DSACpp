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
    int GetHeight();

private:  
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
        RBNode() {                        
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }
		RBNode(T key) {
			this->key = key;
			this->color = Color::Red;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}
        RBNode(T key,Color color) {
            this->key = key
            this->color = color;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }
        RBNode(Color color) {            
            this->color = color;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }
	};
    struct RBNode T_Nil_Node = RBNode(Color::Black);
    RBNode* T_Nil = &T_Nil_Node;
    RBNode* Root = T_Nil;
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
        while(New->parent->color == Color::Red){
            if(New->parent == New->parent->parent->left){
                temp = New->parent->parent->right;
                if(temp->color == Color::Red){
                    New->parent->color = Color::Black;
                    temp->color = Color::Black;
                    New->parent->parent->color = Color::Red;
                    New = New->parent->parent;
                }
                else{
                    if(New == New->parent->right){
                        New = New->parent;
                        rotateLeft(Root, New);
                    }
                    New->parent->color = Color::Black;
                    New->parent->parent->color = Color::Red;
                    rotateRight(Root, New->parent->parent);
                }
            }
            else {
                temp = New->parent->parent->left;
                if(temp->color == Color::Red){
                    New->parent->color = Color::Black;
                    New->color = Color::Black;
                    New->parent->parent->color = Color::Red;
                    New = New->parent->parent;
                }
                else{
                    if(New == New->parent->left){
                        New = New->parent;
                        rotateRight(Root, New);
                    }
                    New->parent->color = Color::Black;
                    New->parent->parent->color = Color::Red;
                    rotateLeft(Root, New->parent->parent);
                }
            }
        }
        Root[0]->color = Color::Black;
    }

    void redBlackInsert(RBNode** top,T key){
        RBNode* z = new RBNode(key);
        RBNode* y = T_Nil;
        RBNode* x = *top;
    
        while(x != T_Nil){
            y = x;
            if(z->key < x->key)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if(y == T_Nil)
            *top = z;
        else if(z->key < y->key)
            y->left = z;
        else
            y->right = z;

        //Init z as a red leaf
        z->left = T_Nil;
        z->right = T_Nil;
        z->color = Color::Red;

        // Ensure the Red-Black property is maintained
        redBlackInsertFixup(top,z);
    }

    int height(RBNode* Root){                 
        if (Root == T_Nil) {
            return 1;
        }
        else {
            int leftHeight = height(Root->left);
            int rightHeight = height(Root->right);
            int h = MAX(leftHeight, rightHeight) + 1;
            return h;
        }        
    }

    RBNode* search(RBNode* root,T key) {
        RBNode* node = root;
        while (node != T_Nil && node->key != key)
        {
            if (key < node->key) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        return node;
    }
    void traverse(RBNode* tree, void (*processItem)(T key)) {
        if (tree == T_Nil)
            return;
        traverse(tree->left,processItem);
        processItem(tree->key);
        traverse(tree->right,processItem);
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
    redBlackInsert(&Root, key);
}
template<typename T>
bool RBTree<T>::Delete(T key){
  return false;
}
template<typename T>
std::optional<T> RBTree<T>::Search(T key){
    RBNode* node = search(Root, key);
    if (node == T_Nil) {
        return std::nullopt;
    }
    return std::make_optional(node->key);
}
template<typename T>
void RBTree<T>::Traverse(void (*processItem)(T key)){
    traverse(Root, processItem);
}
template<typename T>
int RBTree<T>::GetHeight() {
    int h = height(Root);
    return h;
}
#endif // !RBTREE_H
