/**
 * @file 113.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 路径总和 II, https://leetcode-cn.com/problems/path-sum-ii
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_113 {
class Solution {
 public:
  std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> out;
    if (root == nullptr) {
      return out;
    }
    std::vector<int> tmpPath;
    hasPathSum(out, tmpPath, root, targetSum, 0);
    return out;
  }

 private:
  void hasPathSum(std::vector<std::vector<int>>& out, std::vector<int>& tmpPath, TreeNode* root, int targetSum,
                  int currentSum) {
    if (root == nullptr) {
      return;
    }
    int newCurrenSum = currentSum + root->val;
    tmpPath.push_back(root->val);
    if (root->left == nullptr && root->right == nullptr && newCurrenSum == targetSum) {
      out.push_back(std::vector<int>(tmpPath));
      tmpPath.pop_back();
      return;
    }
    if (root->left != nullptr) {
      hasPathSum(out, tmpPath, root->left, targetSum, newCurrenSum);
    }
    if (root->right != nullptr) {
      hasPathSum(out, tmpPath, root->right, targetSum, newCurrenSum);
    }
    tmpPath.pop_back();
  }
};
}  // namespace leetcode_113
