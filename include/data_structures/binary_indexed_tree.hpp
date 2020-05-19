#pragma once
#include <numeric>
#include <vector>

namespace prog_comp {
template <class T> class Binary_indexed_tree {
private:
  std::vector<T> tree;

  void build_tree(std::vector<T> &array, T init) {
    tree.resize(array.size() + 1);
    for (size_t k = 1; k <= array.size(); k++) {
      tree[k] = std::accumulate(array.begin() + k - (k & -k), array.begin() + k,
                                init);
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
  Binary_indexed_tree(std::vector<T> &array, T init) {
    build_tree(array, init);
  }

  T operator[](const size_t index) { return tree[index + 1]; }

  void add(size_t k, T x) {
    k += 1;
    while (k < tree.size()) {
      tree[k] += x;
      k += k & -k;
    }
  }

  T sum_range(size_t a, size_t b) {
    a += 1;
    b += 1;
    if (a > 1)
      return sum(b) - sum(a - 1);
    else
      return sum(b);
  }
};
} // namespace prog_comp
