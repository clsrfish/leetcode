/**
 * @file 0144.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 二叉树的前序遍历 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * @version 0.1
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <stack>
#include <vector>

#include "./model/tree_node.hpp"

namespace leetcode_0144 {
std::string key = "0144";
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> res;
    // preorderTraversalRecursively(root, res);
    preorderTraversalIteratively(root, res);
    return res;
  }

 private:
  void preorderTraversalRecursively(TreeNode* root, std::vector<int>& path) {
    if (root == nullptr) {
      return;
    }
    path.push_back(root->val);
    preorderTraversalRecursively(root->left, path);
    preorderTraversalRecursively(root->right, path);
  }

  void preorderTraversalIteratively(TreeNode* root, std::vector<int>& path) {
    std::stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        path.push_back(root->val);
        if (root->right != nullptr) {
          stk.push(root->right);
        }
        root = root->left;
      }
      if (!stk.empty()) {
        root = stk.top();
        stk.pop();
      }
    }
  }
};
int main() {
  std::cout << key << ": 二叉树的前序遍历" << std::endl;
  return 0;
}
}  // namespace leetcode_0144