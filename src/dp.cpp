#include "../include/dp.hpp"
#include "../include/catch.hpp"
#include<vector>

template <class FowardIterator> long long longest_increasing_sub(const FowardIterator start, const FowardIterator end) {
  std::vector<long long> length(end - start); 
  long long max = 1;
  for (auto i = start; i != end; i++) {
    length[i - start] = 1;
    for (auto j = start; j != i; j++) {
      if(* j <  * i){
        length[i - start] = std::max(length[i - start], length[j - start] + 1);
        if(max < length[i - start]) max = length[i - start];
      }
    }
  }

  return max;
}

TEST_CASE("Longest incresing subsequence", "[longest_increasing_sub]") {

  SECTION( "Array com elementos em ordem crescente" ) {
    const int arr[] = {10, 15, 16, 17, 18}; 
    REQUIRE(longest_increasing_sub(arr, arr + 5) == 5);
  }
  SECTION( "Array com elementos em ordem decrescente" ) {
    const int arr[] = {10, 7, 5, 3, 2}; 
    REQUIRE(longest_increasing_sub(arr, arr + 5) == 1);
  }
  SECTION( "Array com elementos fora de ordem" ) {
    const int arr[] = {10, 7, 11, 13, 5}; 
    REQUIRE(longest_increasing_sub(arr, arr + 5) == 3);
  }
  SECTION( "Passando vector como parametro" ) {
    std::vector<int> v = {10, 7, 11, 13, 5};
    REQUIRE(longest_increasing_sub(v.begin(), v.end()) == 3);
  }
}
