#include <numeric>
#include <vector>
#include "../include/catch.hpp"
#include "../include/data_structures.hpp"

template <class T> std::vector<T> binary_index_tree(std::vector<T> array, T init) {
  std::vector<T> tree(array.size(), 0);

  for (size_t k = 1; k < tree.size(); k++) {
    tree[k] =
        std::accumulate(array.begin() + 1 + k - (k & -k), array.begin() + 1 + k, init);
  }

  return tree;
}


TEST_CASE( "binary index tree" ) {
  SECTION( "Testa a construção de um binary index tree" ) {
    std::vector<int> v = {0, 1, 3, 4, 8, 6, 1, 4, 2};
    std::vector<int> r = {0, 1, 4, 4, 16, 6, 7, 4, 29};
    REQUIRE_THAT(binary_index_tree<int>(v, 0), Catch::Equals(r));
  }
}

