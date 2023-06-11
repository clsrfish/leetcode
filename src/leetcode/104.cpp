/**
 * @file 104.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 二叉树的最大深度 https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * @version 0.1
 * @date 2021-05-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../model/tree_node.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_104 {
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};
} // namespace leetcode_104