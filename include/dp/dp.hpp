#pragma once
#include <vector>

namespace comp_prog {

template <class FowardIterator>
long long longest_increasing_sub(const FowardIterator start,
                                 const FowardIterator end) {
  std::vector<long long> length(end - start);
  long long max = 1;
  for (auto i = start; i != end; i++) {
    length[i - start] = 1;
    for (auto j = start; j != i; j++) {
      if (*j < *i) {
        length[i - start] = std::max(length[i - start], length[j - start] + 1);
        if (max < length[i - start])
          max = length[i - start];
      }
    }
  }

  return max;
}
} // namespace comp_prog
