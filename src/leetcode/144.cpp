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

#include "../model/tree_node.hpp"
#include "../utils/stl_utils.hpp"
namespace leetcode_0144 {
std::string key = "0144";
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> res;
    // preorderTraversalRecursively(root, res);
    preorderTraversalMorris(root, res);
    return res;
  }

 private:
  void preorderTraversalRecursively(TreeNode *root, std::vector<int> &path) {
    if (root == nullptr) {
      return;
    }
    path.push_back(root->val);
    preorderTraversalRecursively(root->left, path);
    preorderTraversalRecursively(root->right, path);
  }

  void preorderTraversalIteratively(TreeNode *root, std::vector<int> &path) {
    std::stack<TreeNode *> stk;
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

  void preorderTraversalMorris(TreeNode *root, std::vector<int> &path) {
    TreeNode *predecessor = nullptr;
    while (root != nullptr) {
      // left is not null
      if (root->left != nullptr) {
        if (root->right == nullptr) {
          path.push_back(root->val);
          root = root->left;
          continue;
        }

        predecessor = root->left;
        while (predecessor->right != nullptr && predecessor->right != root) {
          predecessor = predecessor->right;
        }

        if (predecessor->right == nullptr) {
          // predecessor->right point to root->right
          predecessor->right = root;
          path.push_back(root->val);
          // move to left
          root = root->left;
        } else {
          root = predecessor->right;
          root = root->right;
          predecessor->right = nullptr;
        }
      } else {
        path.push_back(root->val);
        // move to right
        root = root->right;
      }
    }
  }
};
int main() {
  std::cout << key << ": 二叉树的前序遍历" << std::endl;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
  root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));

  auto res = Solution().preorderTraversal(root);

  std::cout << vector2str(res) << std::endl;
  return 0;
}
}  // namespace leetcode_0144