/**
 * @file 102.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 二叉树的层序遍历 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * @version 0.1
 * @date 2021-05-12
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../model/tree_node.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_102 {
class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> res;
    levelOrderRecursively(res, root, 0);
    return res;
  }

  void levelOrderRecursively(std::vector<std::vector<int>> &res, TreeNode *root, unsigned int level) {
    if (root == nullptr) {
      return;
    }

    if (res.size() <= level) {
      std::vector<int> levelRes{root->val};
      res.push_back(levelRes);
    } else {
      res.at(level).push_back(root->val);
    }
    if (root->left != nullptr) {
      levelOrderRecursively(res, root->left, level + 1);
    }
    if (root->right != nullptr) {
      levelOrderRecursively(res, root->right, level + 1);
    }
  }
};
} // namespace leetcode_102