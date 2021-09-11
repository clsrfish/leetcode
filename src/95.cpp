/**
 * @file 95.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 不同的二叉搜索树 II
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * @version 0.1
 * @date 2021-07-03
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
#include <vector>

#include "./model/tree_node.hpp"

namespace leetcode_95 {
class Solution {
 public:
  std::vector<TreeNode*> generateTrees(int n) {
    if (n < 1) {
      return {};
    }
    return generateTreeRecursively(1, n);
  }

 private:
  std::vector<TreeNode*> generateTreeRecursively(int low, int up) {
    if (up < low) {
      return {nullptr};
    }
    std::vector<TreeNode*> allTrees;
    for (int i = low; i <= up; i++) {
      auto leftTrees = generateTreeRecursively(low, i - 1);
      auto rightTrees = generateTreeRecursively(i + 1, up);

      for (auto& left : leftTrees) {
        for (auto& right : rightTrees) {
          TreeNode* root = new TreeNode(i);
          root->left = left;
          root->right = right;
          allTrees.emplace_back(root);
        }
      }
    }
    return allTrees;
  }
};
}  // namespace leetcode_95