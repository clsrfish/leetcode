/**
 * @file 112.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief  路径总和, https://leetcode.cn/problems/path-sum
 * @version 0.1
 * @date 2024-08-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_112 {
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == 0;
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
  }
};
}  // namespace leetcode_112
