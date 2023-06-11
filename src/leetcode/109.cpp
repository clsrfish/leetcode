/**
 * @file 109.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 有序链表转换二叉搜索树, https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
 * @version 0.1
 * @date 2021-09-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../model/list_node.hpp"
#include "../model/tree_node.hpp"

namespace leetcode_109 {
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }
    std::vector<int> nums;
    while (head != nullptr) {
      nums.push_back(head->val);
      head = head->next;
    }
    return sortedArrayToBST(nums, 0, nums.size());
  }

 private:
  TreeNode* sortedArrayToBST(std::vector<int> nums, int start, int end) {
    if (start >= end) {
      return nullptr;
    }
    int rootIndex = (start + end) / 2;
    auto root = new TreeNode(nums[rootIndex]);
    root->left = sortedArrayToBST(nums, start, rootIndex);
    root->right = sortedArrayToBST(nums, rootIndex + 1, end);
    return root;
  }
};
}  // namespace leetcode_109
