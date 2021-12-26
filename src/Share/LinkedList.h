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
class LinkedList
{
private:   
    size_t length = 0;
    shared_ptr<Node<T>> head = nullptr;    

    //busca um elemento com valor x recursivamente
    /*
    * Search the list recursively for a element with the value of x
    * @param l: the head of the list
    * @param x: the value to searched
    */
    std::optional<shared_ptr<Node<T>>> Search(shared_ptr<Node<T>> l,T x) {
        if (l == nullptr)
            return std::nullopt;
        if (l->Item == x) {
            return std::make_optional(l);
        }        
        return Search(l->Next, x);        
    }        
    // busca o sucessor de x recursivamente
    /*
    * Get the successor of x
    * @param l: the head of the list
    * @param x: the value 
    */
    shared_ptr<Node<T>> GetPredecessor(shared_ptr<Node<T>> l,shared_ptr<Node<T>> x) {
        if (l == nullptr || l->Next == nullptr)
            return nullptr;

        if (l->Next == x) {
            return l;
        }
        return GetPredecessor(l->Next, x);
    }
    /*
    * Deletes a given node from the list
    * @param l: the head of the list
    * @param x: the element to be removed from the head.    
    */
    void DeleteNode(shared_ptr<Node<T>> *l,shared_ptr<Node<T>> *x) {
        shared_ptr<Node<T>> p;
        shared_ptr<Node<T>> pred;
        p = *l;
        pred = GetPredecessor(*l, *x);
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
public:
    LinkedList(){                
    }
    LinkedList(initializer_list<T> initList) {                
        for (auto it = initList.begin(); it != initList.end(); ++it) {
            Insert(*it);
        }        
    }
    ~LinkedList(){
    }
    // Insere o elemento no inicio da lista
    /*
    * insert a given value in the begining of the list
    * @param value: the value to be prepended
    */
    void Insert(T value){
        //Prepend(&head, value);
        shared_ptr<Node<T>> p = make_shared<Node<T>>();
        p->Item = value;
        p->Next = head;
        head = p;
        length++;
    }         
    // busca um elemento na lista com o mesmo valor do value passado
    /*
    * Search the list recursively for a element with the value of x
    * @param value: the value to be searched
    */
    std::optional<T> Search(T item){        
        auto nodeOpt = Search(head, item);        
        if (!nodeOpt.has_value())
            return std::nullopt;
        auto node = nodeOpt.value();
        return make_optional(node->Item);
    }
    //deleta um elemento com o mesmo valor do value passado.
    //Se conseguir retorna true, do contrário, false
    /*
    * Deletes a value in the list that it's equal to value.
    * Returns true if deleted, otherwise, false.
    * @param value: the value to be deleted
    */
    bool Delete(T value){
        auto nodeOpt = Search(head,value);
        
        if (!nodeOpt.has_value())
            return false;

        auto node = nodeOpt.value();
        DeleteNode(&head, &node);
        length--;
        return true;
    }
    // somente demonstração,
    // ambos os métodos funcionam, mas minha preferencia é pelo uso de smart pointers

    void BubbleSortWithRawPointers() {
        //TODO:
        if(head == nullptr)
            return;
        Node<T>* pointer = NULL;
        Node<T>* first = head.get();
        pointer = head->Next.get();
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
    
    /*
    * Sort the list with bubble sort algorithm
    */
    void BubbleSort() {
        if (head == nullptr)
            return;
        shared_ptr<Node<T>> pointer = head->Next;
        shared_ptr<Node<T>> first = head;                
        while (pointer != nullptr)
        {
            shared_ptr<Node<T>> p = first;
            shared_ptr<Node<T>> c = pointer;            
            while (p != nullptr)
            {
                if (p->Item > c->Item) {
                    auto temp = c->Item;
                    c->Item = p->Item;
                    p->Item = temp;
                }
                p = p->Next;                
            }            
            pointer = pointer->Next;                 
        }
    }
    //retorna o head, o Node que aponta para o "inicio" da lista.
    /*
    * Returns the head of the list
    */
    shared_ptr<Node<T>> GetHead() {
        return this->head;
    }    
    /*
    * Returns the number of elements in the list
    */
    size_t Size() {
        return this->length;
    }
};
template<typename T>
void printList(LinkedList<T> list) {
    shared_ptr<Node<T>> head = list.GetHead();
    while (head != nullptr)
    {
        std::cout << head->Item << (head->Next == nullptr ? "" : " ,");
        head = head->Next;
    }
    std::cout << std::endl;
}
template<typename T>
void Menu(LinkedList<T> list) {
    bool _continue = true;
    while (_continue)
    {
        std::cout << "i - Insert" << std::endl;
        std::cout << "b - Search" << std::endl;
        std::cout << "d - Delete" << std::endl;
        std::cout << "l - List" << std::endl;
        std::cout << "s - Sort" << std::endl;
        std::cout << "e - Leave" << std::endl;
        char opcao;
        std::cin >> opcao;
        if (opcao == 'i') {
            T value;
            std::cout << "Enter a value: ";
            std::cin >> value;
            list.Insert(value);    
            std::cout << "Inserted Value:" << value << std::endl;
        }
        else if (opcao == 'd') {
            T value;
            std::cin >> value;
            std::cout << "Removed Item: " << list.Delete(value) << std::endl;            
        }
        else if (opcao == 'b') {
            T value;
            std::cin >> value;
            std::optional<T> searchedItem = list.Search(value);
            if (!searchedItem.has_value())
            {
                std::cout << "Given value " << value << "doesn't exists in the list" << std::endl;
            }
            else {                
                std::cout << "Searched Item: " << searchedItem.value() << std::endl;
            }
        }
        else if (opcao == 'l') {
            printList(list);
        }
        else if (opcao == 's') {
            list.BubbleSort();
            printList(list);
        }
        else if (opcao == 'e') {
            _continue = false;
        }
    }
}
#endif
