#include "doctest.h"
#include <Share/LinkedList.h>
#include <memory>
std::unique_ptr<LinkedList<int>> createList() {
    std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
    for (int i = 0; i < 21; ++i) {
        list->Insert(i);
    }
    return list;
}
TEST_SUITE("Linked list test") {    
        
    TEST_CASE("Test element count") {
        auto list = createList();
        CHECK(21 == list->Size());
    }
    TEST_CASE("Test insertion and search of linked list") {        
        auto list = createList();
        auto item = list->Search(10);
        CHECK(10 == item.value());
    }
    TEST_CASE("Test list traverse") {        
        auto list = createList();
        int sumList = 0;
        int sumFor = 0;
        Iterator<int> it = list->GetIteratorFromTail();
        for (int i = 0; i < 21; ++i) {
            sumFor += i;
        }
        sumList += it.GetCurrent().value();
        while (it.Next())
        {
            sumList += it.GetCurrent().has_value() ? it.GetCurrent().value() : 0;
        }
        CHECK(sumFor == sumList);
    }
    //a lista começa a ser traversada do ultimo elemento
    TEST_CASE("Test list traverse 2") {                
        auto list = createList();
        Iterator<int> iterator = list->GetIteratorFromTail();
        for (size_t i = 20; i > 0; i--)
        {
            auto current = iterator.GetCurrent();
            CHECK(current.has_value());
            CHECK(current.value() == i);
            iterator.Next();
        }

    }        
}