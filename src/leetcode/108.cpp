/**
 * @file 108.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 将有序数组转换为二叉搜索树, https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
#include <vector>

#include "../model/tree_node.hpp"

namespace leetcode_108 {
class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return sortedArratToBST(nums, 0, nums.size());
  }

 private:
  TreeNode* sortedArratToBST(std::vector<int>& nums, int start, int end) {
    if (start >= end) {
      return nullptr;
    }
    int rootIndex = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[rootIndex]);
    root->left = sortedArratToBST(nums, start, rootIndex);
    root->right = sortedArratToBST(nums, rootIndex + 1, end);
    return root;
  }
};
}  // namespace leetcode_108
