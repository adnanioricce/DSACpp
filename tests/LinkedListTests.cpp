//#include "doctest.h"
#include "doctest/doctest.h"
#include <Share/LinkedList.h>
#include <memory>
#include <array>
#include <string>
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
        auto it = list->GetHead();
        for (int i = 0; i < 21; ++i) {
            sumFor += i;
        }
        /*sumList += it->Item;
        it = it*/
        while (it != nullptr)
        {
            sumList += it->Item;
            it = it->Next;
        }
        CHECK(sumFor == sumList);
    }
    //a lista começa a ser traversada do ultimo elemento
    TEST_CASE("Test list traverse 2") {                
        auto list = createList();
        auto it = list->GetHead();
        for (size_t i = 20; i > 0; i--)
        {
            auto current = it->Item;            
            CHECK(current == i);
            it = it->Next;
        }
    }
    TEST_CASE("Test deletion") {
        auto expectedList = std::array<int, 6>(
            {1,8,2,5,9,7}
        );
        auto resultList = std::array<int, 6>();
        LinkedList<int> list({ 1,8,254,2,5,9,7 });
        list.Delete(254);
        auto it = list.GetHead();        
        for (int i = expectedList.size() - 1; i >= 0; --i) {            
            if (expectedList[i] != it->Item)
                FAIL("lists don't match, item at index " << i << " is expected to be " << expectedList[i] << " but was " << it->Item);
            it = it->Next;
        }
    }
    TEST_CASE("Test list sorting") {
        // Entrada
        auto testList = std::initializer_list(
            { 7,2,9,6,1,3 }
        );
        //Saida esperada
        auto expectedList = std::array<int, 6>(
            { 1,2,3,6,7,9 }
        );        
        std::cout << "testing sorting " << std::endl;
        LinkedList<int> list(testList);        
        list.BubbleSort();
        auto resultList = std::array<int, 6>();
        //Sort(list);
        auto iterator = list.GetHead();                      
        for (int i = 0; i < 6; i++)
        {
            auto item = iterator->Item;            
            resultList[i] = item;
            iterator = iterator->Next;
        }
        for (size_t i = expectedList.size() - 1; i > 0; i--) {            
            if (resultList[i] != expectedList[i])
                FAIL("lists don't match, at index " << i << " value expected value is " << expectedList[i] << " received value was " << resultList[i]);
                        
        }
    }
    TEST_CASE("Test sorting on empty list") {        
        LinkedList<int> list;
        list.BubbleSort();
    }
    TEST_CASE("Test sorting with one element") {
        LinkedList<int> list;
        list.Insert(5);
        list.BubbleSort();
    }    
}