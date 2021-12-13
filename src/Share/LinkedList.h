#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <memory>
#include <optional>
using namespace std;
template<typename T>
struct Node {
    T Item;
    Node *Next;
};
template<typename T>
class Iterator {
private:
    Node<T>* _tail;    
    Node<T>* _current;
public:
    Iterator(Node<T>* tail) {
        _tail = tail;
        _current = tail;
    }
    optional<T> GetCurrent() {
        if (_current == NULL)
            return nullopt;

        return make_optional(_current->Item);
    }
    bool Next() {
        if (_current == NULL) {
            _current = _tail;
            return false;
        }
            
        _current = _current->Next;
        return true;
    }
};
template<typename T>
class LinkedList
{
private:   
    int length;     
    Node<T> *tail;    

    Node<T>* Search(Node<T> *l,T x) {
        if (l == NULL)
            return NULL;
        if (l->Item == x) {
            return l;
        }        
        return Search(l->Next, x);        
    }
    void Insert(Node<T> **l, T x) {
        Node<T>* p;
        p = (Node<T>*)malloc(sizeof(Node<T>));
        p->Item = x;
        p->Next = *l;
        *l = p;
    }
    Node<T>* ItemAhead(Node<T> *l,Node<T> *x) {
        if (l == NULL || l->Next == NULL)
            return NULL;

        if (l->Next == x) {
            return l;
        }
        return ItemAhead(l->Next, x);
    }
    void DeleteNode(Node<T> **l,Node<T> **x) {
        Node<T>* p;
        Node<T>* pred;
        p = *l;
        pred = ItemAhead(*l, *x);
        if (pred == NULL) {
            *l = p->Next;
        }
        else {
            pred->Next = (*x)->Next;
        }
        free(*x);
    }    
public:
    LinkedList(){        
        tail = NULL;        
        length = 0;
    }
    ~LinkedList(){                
        Node<T>* p;
        while (tail != NULL)
        {
            p = tail;
            tail = tail->Next;
            delete p;
        }        
    }
    void Insert(T item){
        Insert(&tail,item);
        length++;
    }

    std::optional<T> Search(T item){        
        auto node = Search(tail, item);
        if (node == NULL)
            return std::nullopt;
        return std::make_optional(item);
    }
    void Delete(T item){
        Node<T>* node = Search(item);
        
        if (node == NULL)
            return;

        DeleteNode(&tail, &node);
        length--;
    }    
    Iterator<T> GetIteratorFromTail() {
        return Iterator<T>(this->tail);
    }
    int Size() {
        return this->length;
    }
};

template<typename T>
void Menu(LinkedList<T> list) {
    std::cout << "i - Insert" << std::endl;
    std::cout << "s - Search" << std::endl;
    std::cout << "d - Delete" << std::endl;
    char opcao;
    opcao >> std::cin;
    if (opcao == 'i') {
        T value;
        value >> std::cin;
        list.Inserir(value);
        return;
    }
    if (opcao == 'd') {
        T value;
        value >> std::cin;
        std::cout << "Removed Item: " << list.Delete(value) << std::endl;
        return;
    }
    if (opcao == 's') {
        T value;
        value >> std::cin;
        Node<T>* searchedItem = list.Search(value);
        std::cout << "Searched Item: " << searchedItem->Item << std::endl;
        return;
    }
}
#endif
