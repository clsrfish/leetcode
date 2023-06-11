/**
 * @file 106.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 从中序与后序遍历序列构造二叉树,
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_106 {
class Solution {
 private:
  std::map<int, int> indcies;

 private:
  TreeNode* buildTree(std::vector<int>& inorder, int inorderStart, int inorderEnd, std::vector<int>& postorder,
                      int postorderStart, int postorderEnd) {
    if (inorderStart > inorderEnd) {
      return nullptr;
    }
    int rootVal = postorder[postorderEnd];
    TreeNode* root = new TreeNode(rootVal);
    int rootIndex = indcies[rootVal];

    root->left = buildTree(inorder, inorderStart, rootIndex - 1, postorder, postorderStart,
                           postorderStart + rootIndex - inorderStart - 1);
    root->right = buildTree(inorder, rootIndex + 1, inorderEnd, postorder, postorderStart + rootIndex - inorderStart,
                            postorderEnd - 1);

    return root;
  }

 public:
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    for (int i = 0; i < inorder.size(); i++) {
      indcies[inorder[i]] = i;
    }

    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
};
}  // namespace leetcode_106
