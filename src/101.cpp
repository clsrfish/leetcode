/**
 * @file 101.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 对称二叉树 https://leetcode-cn.com/problems/symmetric-tree/
 * @version 0.1
 * @date 2021-05-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
#include <vector>

#include "./model/tree_node.hpp"

namespace leetcode_101 {
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return isSymmetric(root->left, root->right);
  }

  bool isSymmetric(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p != nullptr && q != nullptr) {
      return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }

    return false;
  }
};

// 非递归
class Solution2 {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    std::vector<TreeNode *> nodes1, nodes2;
    nodes1.push_back(root->left);
    nodes1.push_back(root->right);
    while (!nodes1.empty() || !nodes2.empty()) {
      std::vector<TreeNode *> &currentLayer = nodes1.empty() ? nodes2 : nodes1;
      std::vector<TreeNode *> &nextLayer = nodes1.empty() ? nodes1 : nodes2;

      nextLayer.resize(currentLayer.size() * 2);

      size_t curLayerNodeCount = currentLayer.size();
      bool allChildrenNull = true;
      for (size_t i = 0; i < curLayerNodeCount / 2; i++) {
        TreeNode *head = currentLayer.at(i);
        size_t tailIndex = curLayerNodeCount - 1 - i;
        TreeNode *tail = currentLayer.at(tailIndex);
        if ((head == nullptr && tail == nullptr) || (head != nullptr && tail != nullptr && head->val == tail->val)) {
          nextLayer.at(i * 2) = head != nullptr ? head->left : nullptr;
          nextLayer.at(i * 2 + 1) = head != nullptr ? head->right : nullptr;
          nextLayer.at(tailIndex * 2) = tail != nullptr ? tail->left : nullptr;
          nextLayer.at(tailIndex * 2 + 1) = tail != nullptr ? tail->right : nullptr;
          allChildrenNull = allChildrenNull && nextLayer.at(i * 2) != nullptr && nextLayer.at(i * 2 + 1) != nullptr &&
                            nextLayer.at(tailIndex * 2) != nullptr && nextLayer.at(tailIndex * 2 + 1) != nullptr;
        } else {
          return false;
        }
      }
      if (allChildrenNull) {
        return true;
      }
      currentLayer.clear();
    }

    return true;
  }
};
}  // namespace leetcode_101