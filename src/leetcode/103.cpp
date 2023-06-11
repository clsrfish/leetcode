/**
 * @file 103.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 二叉树的锯齿形层序遍历 https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
 * @version 0.1
 * @date 2021-05-14
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_103 {
class Solution {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    std::vector<TreeNode *> nodes;
    nodes.push_back(root);
    int level = 0;
    while (!nodes.empty()) {
      size_t count = nodes.size();
      std::vector<int> levelRes;
      for (size_t i = 0; i < count; i++) {
        TreeNode *node = nodes.at(i);

        levelRes.push_back(node->val);
        if (node->left != nullptr) {
          nodes.push_back(node->left);
        }
        if (node->right != nullptr) {
          nodes.push_back(node->right);
        }
      }
      nodes.erase(nodes.begin(), nodes.begin() + count);
      if ((level & 1) == 1) {
        std::reverse(levelRes.begin(), levelRes.end());
      }
      res.push_back(levelRes);
      level++;
    }

    return res;
  }
};
}  // namespace leetcode_103