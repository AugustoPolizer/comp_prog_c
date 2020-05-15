#pragma once
#include <numeric>
#include <vector>
#include "../catch.hpp"

using std::vector;
using std::accumulate;

namespace prog_comp {
template <class T> class Binary_indexed_tree {
private:
  vector<T> tree;

  void build_tree(vector<T> &array, T init) {
    tree.resize(array.size());
    for (size_t k = 1; k < array.size(); k++) {
      tree[k] = accumulate(array.begin() + 1 + k - (k & -k), array.begin() + 1, init);
    }
  }

  T sum(size_t k) {
    T s = 0;
    while (k >= 1) {
      s += tree[k];
      k -= k & -k;
    }
    return s;
  }

public:
  Binary_indexed_tree(vector<T> &array, T init) { build_tree(array, init); }

  void add(size_t k, T x) {
    while (k <= tree.size()) {
      tree[k] += x;
      k += k & -k;
    }
  }

  T sum_range(size_t a, size_t b) {
    if (a > 1)
      return sum(b) - sum(a - 1);
    else
      return sum(b);
  }
};
} // namespace prog_comp


