/**
 * @file 110.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 平衡二叉树, https://leetcode-cn.com/problems/balanced-binary-tree
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_110 {
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return avlTreeDepth(root) >= 0;
  }

 private:
  int avlTreeDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int leftDepth = avlTreeDepth(root->left);
    int rightDepth = avlTreeDepth(root->right);
    if (leftDepth == -1 || rightDepth == -1 || leftDepth - rightDepth > 1 || rightDepth - leftDepth > 1) {
      return -1;
    }
    return std::max(leftDepth, rightDepth) + 1;
  }
};
}  // namespace leetcode_110
