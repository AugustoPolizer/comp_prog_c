#include "../../include/data_structures/data_structures.hpp"
#include "../../include/data_structures/test.hpp"
#include "../../include/catch.hpp"
#include<vector>

using std::vector;

TEST_CASE("Binary indexed tree"){
  vector<int> dataTest = {1, 3, 4, 8, 6, 1, 4, 2};
  prog_comp::Binary_indexed_tree<int> tree (dataTest, 0);

  SECTION( "Testando a Implementação do metodo sum_range para um rangue igual a 1" ) {
    
    REQUIRE(tree.sum_range(1,1) == 1);
    REQUIRE(tree.sum_range(2,2) == 3);
  }
}
