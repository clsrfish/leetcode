/**
 * @file 0094.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 二叉树的中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

#include "./model/tree_node.hpp"
#include "./utils/stl_utils.hpp"

namespace leetcode_0094 {
std::string key = "0094";
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    auto traversal = std::vector<int>();
    traversalRecursively(root, traversal);
    return traversal;
  }

 private:
  void traversalRecursively(TreeNode* root, std::vector<int>& path) {
    if (root == nullptr) {
      return;
    }
    auto left = root->left;
    if (left != nullptr) {
      traversalRecursively(left, path);
    }
    path.push_back(root->val);
    auto right = root->right;
    if (right != nullptr) {
      traversalRecursively(right, path);
    }
  }
  // TODO: traversal tree with iterator
  void traversalIteratively(TreeNode* root, std::vector<int>& path) {
    auto stack = std::vector<TreeNode*>();
    auto left = root;
    while (left != nullptr) {
      stack.push_back(left);
      left = left->left;
    }
    while (!stack.empty()) {
      left = stack.back();
      path.push_back(left->val);
    }
  }
};
int main() {
  std::cout << key << ": 二叉树的中序遍历" << std::endl;
  return 0;
}
}  // namespace leetcode_0094