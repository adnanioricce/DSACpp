#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <memory>
#include <optional>
#include <iostream>
using namespace std;
template<typename T>
struct Node {
    T Item;
    shared_ptr<Node> Next;
};
template<typename T>
class Iterator {
private:
    shared_ptr<Node<T>> _tail;
    shared_ptr<Node<T>> _current;
public:
    Iterator(shared_ptr<Node<T>> tail) {
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
    void Swap(Iterator<T>& rhs) {
        if (rhs._current == nullptr)
            return;
        shared_ptr<Node<T>> rhsNode = rhs._current;        
        auto temp = rhsNode->Item;
        rhsNode->Item = _current->Item;
        _current->Item = temp;
    }
};
template<typename T>
class LinkedList
{
private:   
    int length;     
    shared_ptr<Node<T>> tail;
    shared_ptr<Node<T>> head;

    std::optional<shared_ptr<Node<T>>> Search(shared_ptr<Node<T>> l,T x) {
        if (l == nullptr)
            return std::nullopt;
        if (l->Item == x) {
            return std::make_optional(l);
        }        
        return Search(l->Next, x);        
    }
    
    void AppendAtStart(shared_ptr<Node<T>>* l, T x) {
        shared_ptr<Node<T>> p = make_shared<Node<T>>();
        //p = (Node<T>*)malloc(sizeof(Node<T>));
        p->Item = x;
        p->Next = *l;
        *l = p;
    }
    void AppendAtEnd(shared_ptr<Node<T>>* head,shared_ptr<Node<T>>* tail, T x) {
        Node<T> pointer = new Node<T>();
        pointer->Item = x;
        pointer->Next = nullptr;
        if (*head == nullptr) {
            *head = pointer;
        }
        else {
            (*tail)->Next = pointer;
        }
        (*tail) = pointer;
    }
    void AppendAtEnd(const T& item)
    {
        shared_ptr<Node<T>> pointer;;
        pointer->Item = item;
        pointer->Next = nullptr;
        if (head == nullptr) {
            head = pointer;
        }
        else {
            tail->Next = pointer;
        }
        tail = pointer;
    }
    shared_ptr<Node<T>> ItemAhead(shared_ptr<Node<T>> l,shared_ptr<Node<T>> x) {
        if (l == nullptr || l->Next == nullptr)
            return nullptr;

        if (l->Next == x) {
            return l;
        }
        return ItemAhead(l->Next, x);
    }
    /*
    * Deletes a given node from the list
    * @param l: the tail of the list
    * @param x: the element to be removed from the tail.    
    */
    void DeleteNode(shared_ptr<Node<T>> *l,shared_ptr<Node<T>> *x) {
        shared_ptr<Node<T>> p;
        shared_ptr<Node<T>> pred;
        p = *l;
        pred = ItemAhead(*l, *x);
        if (pred == nullptr) {
            *l = p->Next;
        }
        else {
            //remove o elemento substituindo o endereço do predecessor com o endereço do sucessor do elemento.
            pred->Next = (*x)->Next;
        }
        //libera a memória usada pelo pointeiro deletado.
        (*x).reset();        
    }    
    void VisualizeCollection() {
        T* arr = new T[length];
        shared_ptr<Node<T>> it = tail;
        for (size_t i = 0; i < length; ++i) {
            arr[i] = it->Item;
            it = it->Next;
        }
        for (size_t i = 0; i < length; ++i) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
        free(arr);
    }
public:
    LinkedList(){        
        tail = nullptr;   
        head = nullptr;
        length = 0;
    }
    LinkedList(initializer_list<T> initList) {
        tail = nullptr;
        head = nullptr;
        length = 0;
        for (auto it = initList.begin(); it != initList.end(); ++it) {
            InsertAtStart(*it);
        }        
    }
    ~LinkedList(){
    }
    void InsertAtStart(T item){
        AppendAtStart(&tail, item);
        length++;
    }
    void InsertAtEnd(T item) {
        AppendAtEnd(item);
        length++;
    }        
    std::optional<T> Search(T item){        
        auto node = Search(tail, item);        
        return item;
    }
    bool Delete(T item){
        auto nodeOpt = Search(tail,item);
        
        if (!nodeOpt.has_value())
            return false;

        auto node = nodeOpt.value();
        DeleteNode(&tail, &node);
        length--;
        return true;
    }
    void BubbleSortWithRawPointers() {
        //TODO:
        if(tail == nullptr)
            return;
        Node<T>* pointer = NULL;
        Node<T>* first = tail.get();
        pointer = tail->Next.get();
        while (pointer != NULL)
        {
            Node<T>* p = first;
            Node<T>* c = pointer;
            while (p != NULL)
            {
                if(p->Item > c->Item){
                    auto temp = c->Item;
                    c->Item = p->Item;
                    p->Item = temp;
                }
                p = p->Next.get();
            }
            pointer = pointer->Next.get();
        }
                
    }
    void BubbleSort() {
        if (tail == nullptr)
            return;
        shared_ptr<Node<T>> pointer = tail->Next;
        shared_ptr<Node<T>> first = tail;        
        int contagem = 0;
        while (pointer != nullptr)
        {
            shared_ptr<Node<T>> p = first;
            shared_ptr<Node<T>> c = pointer;
            std::cout << "Rodada: " << contagem << "\n Antes" << std::endl;
            VisualizeCollection();
            while (p != nullptr)
            {
                if (p->Item > c->Item) {
                    auto temp = c->Item;
                    c->Item = p->Item;
                    p->Item = temp;
                }
                p = p->Next;                
            }
            std::cout << " Depois " << std::endl;
            VisualizeCollection();
            pointer = pointer->Next;     
            contagem++;
        }
    }
    Iterator<T> GetIteratorFromTail() {
        return Iterator<T>(this->tail);
    }    
    int Size() {
        return this->length;
    }
};
template<typename T>
void Sort(LinkedList<T>& list) {
    Iterator<T> pointer = list.GetIteratorFromTail();
    Iterator<T> current = list.GetIteratorFromTail();
    optional<T> pointerOpt = pointer.GetCurrent();    
    int index = 0;    
    int innerIndex = 0;
    std::array<T, 6> arr;
    optional<T> next = current.GetCurrent();
    while (pointerOpt.has_value())
    {                   
        while (next.has_value())
        {               
            if (pointerOpt.value() < next.value()) {                    
                pointer.Swap(current);
            }
            current.Next();
            next = current.GetCurrent();
            
            innerIndex++;
        }
        index += pointer.Next();
        pointerOpt = pointer.GetCurrent();
        current = list.GetIteratorFromTail();
        next = current.GetCurrent();
        //current.Next();
           
    }
}
template<typename T>
void Menu(LinkedList<T> list) {
    bool _continue = true;
    while (_continue)
    {
        std::cout << "i - Insert" << std::endl;
        std::cout << "b - Search" << std::endl;
        std::cout << "d - Delete" << std::endl;
        std::cout << "s - leave" << std::endl;
        char opcao;
        opcao >> std::cin;
        if (opcao == 'i') {
            T value;
            value >> std::cin;
            list.Inserir(value);    
            std::cout << "Inserted Value:" << value << std::endl;
        }
        else if (opcao == 'd') {
            T value;
            value >> std::cin;
            std::cout << "Removed Item: " << list.Delete(value) << std::endl;            
        }
        else if (opcao == 'b') {
            T value;
            value >> std::cin;
            Node<T>* searchedItem = list.Search(value);
            std::cout << "Searched Item: " << searchedItem->Item << std::endl;            
        }
        else if (opcao == 's') {
            _continue = false;
        }
    }
}
#endif
