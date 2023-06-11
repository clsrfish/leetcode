/**
 * @file 105.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 从前序与中序遍历序列构造二叉树,
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 * @version 0.1
 * @date 2021-09-11
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_105 {
class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    auto root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    return root;
  }

 private:
  TreeNode* buildTree(std::vector<int>& preorder, int preorderStart, int preorderEnd, std::vector<int>& inorder,
                      int inorderStart, int inorderEnd) {
    if (preorderStart >= preorderEnd) {
      return nullptr;
    }

    int rootVal = preorder[preorderStart];
    TreeNode* root = new TreeNode(rootVal);

    int rootInorderIndex = -1;
    for (int i = inorderStart; i < inorderEnd; i++) {
      if (inorder[i] == rootVal) {
        rootInorderIndex = i;
        break;
      }
    }
    if (rootInorderIndex == -1) {
      return root;
    }

    root->left = buildTree(preorder, preorderStart + 1, preorderStart + 1 + rootInorderIndex - inorderStart, inorder,
                           inorderStart, rootInorderIndex);

    root->right = buildTree(preorder, preorderStart + 1 + rootInorderIndex - inorderStart, preorderEnd, inorder,
                            rootInorderIndex + 1, inorderEnd);
    return root;
  }
};
}  // namespace leetcode_105