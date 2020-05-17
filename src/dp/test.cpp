#include "../../include/catch.hpp"
#include "../../include/dp/dp.hpp"
#include<vector>

TEST_CASE("Longest incresing subsequence", "[longest_increasing_sub]") {

  SECTION( "Array com elementos em ordem crescente" ) {
    const int arr[] = {10, 15, 16, 17, 18}; 
    REQUIRE(comp_prog::longest_increasing_sub(arr, arr + 5) == 5);
  }
  SECTION( "Array com elementos em ordem decrescente" ) {
    const int arr[] = {10, 7, 5, 3, 2}; 
    REQUIRE(comp_prog::longest_increasing_sub(arr, arr + 5) == 1);
  }
  SECTION( "Array com elementos fora de ordem" ) {
    const int arr[] = {10, 7, 11, 13, 5}; 
    REQUIRE(comp_prog::longest_increasing_sub(arr, arr + 5) == 3);
  }
  SECTION( "Passando vector como parametro" ) {
    std::vector<int> v = {10, 7, 11, 13, 5};
    REQUIRE(comp_prog::longest_increasing_sub(v.begin(), v.end()) == 3);
  }
}
