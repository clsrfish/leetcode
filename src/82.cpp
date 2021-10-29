/**
 * @file 82.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 * @version 0.1
 * @date 2021-10-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "./model/list_node.hpp"
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace leetcode_82 {
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *newHead = nullptr, *tail = nullptr;
    ListNode *nexTail = head, *probe = nullptr;
    while (nexTail != nullptr) {
      bool duplicate = false;
      probe = nexTail->next;
      while (probe != nullptr && probe->val == nexTail->val) {
        probe = probe->next;
        duplicate = true;
      }
      if (!duplicate) {
        if (newHead == nullptr) {
          newHead = nexTail;
          tail = nexTail;
        } else {
          tail->next = nexTail;
          tail = nexTail;
        }
      }
      nexTail = probe;
    }
    if (tail != nullptr) {
      tail->next = nullptr;
    }
    return newHead;
  }
};
} // namespace leetcode_82
