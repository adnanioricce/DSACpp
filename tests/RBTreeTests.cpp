#include <doctest/doctest.h>
#include <Share/RBTree.h>

TEST_CASE("test insertion"){
  RBtree<int> tree;
  tree.Insert(10);
  CHECK(10 == tree.Search(10));
}
