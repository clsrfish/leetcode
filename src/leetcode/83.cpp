/**
 * @file 83.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
 * @version 0.1
 * @date 2021-10-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "../model/list_node.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_83 {
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head, *next = nullptr;
    while (cur != nullptr) {
      next = cur->next;
      while (next != nullptr && cur->val == next->val) {
        auto tmp = next;
        next = next->next;
        delete tmp;
      }
      cur->next = next;
      cur = cur->next;
    }
    return head;
  }
};
} // namespace leetcode_83
