/**
 * @file 98.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 验证二叉搜索树, https://leetcode-cn.com/problems/validate-binary-search-tree/.
 * @version 0.1
 * @date 2021-09-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <climits>
#include <iostream>
#include <string>
#include <vector>

#include "./model/tree_node.hpp"

namespace leetcode_98 {
class Solution {
 public:
  //  TODO: improve performance
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }

    bool leftValid = isValidBST(root->left);
    bool rightValid = isValidBST(root->right);
    if (!leftValid || !rightValid) {
      return false;
    }

    int rootVal = root->val;
    if (root->left != nullptr) {
      int leftVal = maxTreeVal(root->left);
      if (rootVal <= leftVal) {
        return false;
      }
    }
    if (root->right != nullptr) {
      int rightVal = minTreeVal(root->right);
      if (rootVal >= rightVal) {
        return false;
      }
    }

    return true;
  }

  int maxTreeVal(TreeNode* node) {
    if (node == nullptr) {
      return INT_MIN;
    }
    int max = node->val;

    if (node->right != nullptr) {
      int maxRight = maxTreeVal(node->right);
      if (max < maxRight) {
        max = maxRight;
      }
    }
    if (node->left != nullptr) {
      int maxLeft = maxTreeVal(node->left);
      if (max < maxLeft) {
        max = maxLeft;
      }
    }
    return max;
  }

  int minTreeVal(TreeNode* node) {
    if (node == nullptr) {
      return INT_MAX;
    }
    int min = node->val;

    if (node->right != nullptr) {
      int minRight = minTreeVal(node->right);
      if (min > minRight) {
        min = minRight;
      }
    }
    if (node->left != nullptr) {
      int minLeft = minTreeVal(node->left);
      if (min > minLeft) {
        min = minLeft;
      }
    }
    return min;
  }
};
}  // namespace leetcode_98