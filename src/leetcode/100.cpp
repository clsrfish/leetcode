/**
 * @file 100.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 相同的树 https://leetcode-cn.com/problems/same-tree
 * @version 0.1
 * @date 2021-05-06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../model/tree_node.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_100 {
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    } else if (p != nullptr && q != nullptr && p->val == q->val) {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
      return false;
    }
  }
};
} // namespace leetcode_100