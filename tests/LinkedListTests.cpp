#include "doctest.h"
#include <Share/LinkedList.h>
#include <memory>
#include <array>
#include <string>
std::unique_ptr<LinkedList<int>> createList() {
    std::unique_ptr<LinkedList<int>> list(new LinkedList<int>());
    for (int i = 0; i < 21; ++i) {
        list->InsertAtStart(i);
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
    TEST_CASE("Test list sorting") {
        // Entrada
        auto testList = std::initializer_list(
            { 7,2,9,6,1,3 }
        );
        //Saida esperada
        auto expectedList = std::array<int, 6>(
            { 1,2,3,6,7,9 }
        );        
        LinkedList<int> list(testList);        
        list.BubbleSort();
        auto resultList = std::array<int, 6>();
        //Sort(list);
        auto iterator = list.GetIteratorFromTail();                      
        for (int i = 0; i < 6; i++)
        {
            auto opt = iterator.GetCurrent();
            if (!opt.has_value())
                FAIL("sizes don't match");
            resultList[i] = opt.value();
            iterator.Next();
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
        list.InsertAtStart(5);
        list.BubbleSortWithRawPointers();
    }
    //TEST_CASE("Test sorting with external function") {
    //    auto expectedList = std::array<int, 6>(
    //        { 1,2,3,6,7,9 }
    //    );
    //    auto resultList = std::array<int, 6>();
    //    LinkedList<int> list({ 7,2,9,6,1,3 });
    //    Sort(list);
    //    auto iterator = list.GetIteratorFromTail();
    //    for (size_t i = 0; i < 6; i++)
    //    {
    //        auto opt = iterator.GetCurrent();
    //        if (!opt.has_value())
    //            FAIL("sizes don't match");
    //        resultList[i] = opt.value();
    //        iterator.Next();
    //    }
    //    for (size_t i = expectedList.size() - 1; i > 0; i--) {
    //        //auto current = iterator.GetCurrent();
    //        /*if (!current.has_value()) {
    //            FAIL("The size of the expected list and the actual list don't match. list failed at " << i);
    //        }*/
    //        if (resultList[i] != expectedList[i])
    //            FAIL("lists don't match, at index " << i << " value expected value is " << expectedList[i] << " received value was " << resultList[i]);

    //    }
    //}
}