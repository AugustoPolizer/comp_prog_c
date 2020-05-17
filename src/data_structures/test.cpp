#include "../../include/catch.hpp"
#include "../../include/data_structures/data_structures.hpp"
#include <vector>

using std::vector;

TEST_CASE("Binary indexed tree") {
  vector<int> dataTest = {1, 3, 4, 8, 6, 1, 4, 2};
  prog_comp::Binary_indexed_tree<int> tree(dataTest, 0);

  SECTION(
      "Testando a Implementação do metodo sum_range para um rangue igual a 1") {

    REQUIRE(tree.sum_range(0, 0) == 1);
    REQUIRE(tree.sum_range(1, 1) == 3);
  }

  SECTION("Testando a Implementação do metodo add") {

    tree.add(0, 10);
    tree.add(7, 5);
    tree.add(4, 3);

    REQUIRE(tree.sum_range(0, 7) == 47);
    REQUIRE(tree.sum_range(4, 7) == 21);
    REQUIRE(tree.sum_range(0, 0) == 11);
  }

  SECTION("Testando o operador []") {

    REQUIRE(tree[7] == 29);
    REQUIRE(tree[0] == 1);
    REQUIRE(tree[3] == 16);

  }
}
