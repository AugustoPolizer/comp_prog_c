#pragma once
#include <utility>
#include <vector>

namespace comp_prog {

template <class FowardIterator>
std::pair<size_t, size_t> sub_array_sum(FowardIterator start,
                                        FowardIterator end, long long key) {

  std::pair<size_t, size_t> result = std::make_pair(0, 0);
  long long sum = 0;
  auto j = start;
  for (auto i = start; i != end; i++) {
    while (j != end && sum < key) {
      sum += *j;
      j++;
    }
    if (sum == key) {
      result.first = i - start;
      result.second = j - start - 1;
      break;
    }
    sum -= *i;
  }

  return result;
}

} // namespace comp_prog
