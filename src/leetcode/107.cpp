/**
 * @file 107.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 二叉树的层序遍历 II, https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
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

namespace leetcode_107 {
class Solution {
 public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> out;
    levelOrderBottom(out, root, 0);
    if (out.size() > 1) {
      std::reverse(out.begin(), out.end());
    }
    return out;
  }

 private:
  void levelOrderBottom(std::vector<std::vector<int>>& out, TreeNode* root, int level) {
    if (root == nullptr) {
      return;
    }
    if (out.size() > level) {
      out[level].push_back(root->val);
    } else {
      out.emplace_back(std::vector<int>{root->val});
    }

    levelOrderBottom(out, root->left, level + 1);
    levelOrderBottom(out, root->right, level + 1);
  }
};
}  // namespace leetcode_107
