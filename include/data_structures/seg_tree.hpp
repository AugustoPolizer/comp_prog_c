#pragma once

#include <cmath>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

namespace prog_comp {
template <class T> class Segment_tree {
private:
  std::vector<T> tree;
  size_t n;

  T build_tree(size_t a, size_t b, size_t k, const std::vector<T> &array,
               const T init) {
    if (a == b) {
      if (a < array.size())
        return array[a];
      else
        return init;
    } else {
      if(k >= tree.size())
        return 0;
      tree[k] = build_tree(a, b / 2, 2 * k, array, init) +
                build_tree(b / 2, b / 2 + 1, 2 * k + 1, array, init);
      return tree[k];
    }
  }

public:
  
  Segment_tree(const std::vector<T> &array, const T init) {
    n = 2 << size_t(std::ceil(std::log2(array.size())));
    cout << n << endl;
    tree.resize(2 * n);
    build_tree(0,n,1,array, init);
    for (auto i: tree)
      cout << i << " ";
    cout << endl;
  }

  T sum_range(size_t a, size_t b) {
    a += n;
    b += n;
    T sum = 0;
    while (a <= b) {
      if (a % 2 == 1) sum += tree[a++];
      if (b % 2 == 0) sum += tree[b--];
    }
    
    return sum;
  }

  void update(size_t k, T x ){
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
      tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
  }

};
} // namespace prog_comp
