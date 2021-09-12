/**
 * @file 112.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief  路径总和, https://leetcode-cn.com/problems/path-sum
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "./model/tree_node.hpp"

namespace leetcode_112 {
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    return hasPathSum(root, targetSum, 0);
  }

 private:
  bool hasPathSum(TreeNode* root, int targetSum, int currentSum) {
    if (root == nullptr) {
      return targetSum == currentSum;
    }
    int newCurrenSum = currentSum + root->val;
    if (root->left == nullptr && root->right == nullptr && newCurrenSum == targetSum) {
      return true;
    }
    if (root->left != nullptr) {
      bool hasPath = hasPathSum(root->left, targetSum, newCurrenSum);
      if (hasPath) {
        return true;
      }
    }
    if (root->right != nullptr) {
      bool hasPath = hasPathSum(root->right, targetSum, newCurrenSum);
      if (hasPath) {
        return true;
      }
    }
    return false;
  }
};
}  // namespace leetcode_112
