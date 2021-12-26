#include "doctest/doctest.h"
#include <Share/Queue.h>

TEST_CASE("Enqueue and Dequeue tests"){
    //Arrange
    Queue<int> queue(10);
    // Act
    queue.Enqueue(3457);
    for(int i = 0;i < 20;i++){
        queue.Enqueue(i);
    }
    // Assert
    CHECK(3457 == queue.Dequeue());
}