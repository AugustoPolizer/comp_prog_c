#include "../include/common.hpp"
#include "../include/catch.hpp"
#include <utility>
#include <vector>

template <class FowardIterator>
std::pair<size_t, size_t> sub_array_sum(FowardIterator start, FowardIterator end, long long key) {

  std::pair<size_t, size_t> result = std::make_pair(0, 0);
  long long sum = 0;
  auto j = start;
  for (auto i = start; i != end; i++) {
    while(j != end && sum < key){
      sum += *j;
      j++;
    } 
    if(sum == key){
      result.first = i - start;
      result.second = j - start - 1;
      break;
    }
    sum -= *i;
  }

  return result;
}

TEST_CASE ( "Sub array sum" ) {
  SECTION ( "Array que possui a soma no sub array" ) { 
    const int arr[] = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = sub_array_sum(arr, arr + 8, 8); 
    REQUIRE(r.first == 2);
    REQUIRE(r.second == 4);
  }
  SECTION ( "Array que nao possui a soma no sub array" ) { 
    const int arr[] = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = sub_array_sum(arr, arr + 8, 20); 
    REQUIRE(r.first == 0);
    REQUIRE(r.second == 0);
  }
  SECTION ( "Testando a funcao com um vector" ) { 
    std::vector<int> v = {1, 3, 2, 5, 1, 1, 2, 3};
    auto r = sub_array_sum(v.begin(), v.end(), 8); 
    REQUIRE(r.first == 2);
    REQUIRE(r.second == 4);
  }
}
