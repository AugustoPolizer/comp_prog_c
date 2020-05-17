#include "../../include/catch.hpp"
#include "../../include/common/common.hpp"

TEST_CASE ( "Sub array sum" ) {
  SECTION ( "Array que possui a soma no sub array" ) { 
    const int arr[] = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = comp_prog::sub_array_sum(arr, arr + 8, 8); 
    REQUIRE(r.first == 2);
    REQUIRE(r.second == 4);
  }
  SECTION ( "Array que nao possui a soma no sub array" ) { 
    const int arr[] = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = comp_prog::sub_array_sum(arr, arr + 8, 20); 
    REQUIRE(r.first == 0);
    REQUIRE(r.second == 0);
  }
  SECTION ( "Testando a funcao com um vector" ) { 
    std::vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = comp_prog::sub_array_sum(v.begin(), v.end(), 8); 
    REQUIRE(r.first == 2);
    REQUIRE(r.second == 4);
  }
}
