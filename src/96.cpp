/**
 * @file 96.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 不同的二叉搜索树
 * https://leetcode-cn.com/problems/unique-binary-search-trees/
 * @version 0.1
 * @date 2021-07-03
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_96 {
class Solution {
 public:
  int numTrees(int n) {
    if (n <= 1) {
      return 1;
    }
    int* cache = new int[n + 1];
    cache[0] = 1;
    cache[1] = 1;
    int res = 0;
    for (int i = 2; i <= n; i++) {
      res = 0;
      for (int j = 0; j < i; j++) {
        res += cache[j] * cache[i - 1 - j];
      }
      cache[i] = res;
    }
    // f(0) = 1
    // f(1) = 1
    // f(2) = f(0) * f(1) + f(1) * f(0)
    // f(3) = f(0) * f(2) + f(1) * f(1) + f(2) * f(0)
    // f(4) = f(0) * f(3) + f(1) * f(2) + f(2) * f(1) + f(3) * f(0)
    delete[] cache;
    return res;
  }
};
}  // namespace leetcode_96