#include "doctest.h"
#include <Share/Stack.h>

TEST_CASE("Testing push and pop behavior"){
    //Arrange
    Stack<int> stack;
    for (int i = 0; i < 21; ++i) {
        stack.Push(i);        
    }
    auto poppedItem = stack.Pop();    
    // Assert
    CHECK(20 == poppedItem);
}