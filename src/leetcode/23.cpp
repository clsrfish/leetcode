/**
 * @file 0023.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 合并 K 个升序链表 https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * @version 0.1
 * @date 2021-03-31
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <queue>
#include <vector>

#include "../model/list_node.hpp"

namespace leetcode_23 {

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    auto cmp = [](ListNode* l, ListNode* r) { return l->val > r->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);

    ListNode* merged = nullptr;
    ListNode* mergedPoint = nullptr;

    for (auto&& list : lists) {
      if (list == nullptr) {
        continue;
      }

      minHeap.push(list);
    }

    while (true) {
      if (minHeap.empty()) {
        if (mergedPoint != nullptr) {
          mergedPoint->next = nullptr;
        }
        break;
      }

      auto list = minHeap.top();
      minHeap.pop();

      if (merged == nullptr) {
        merged = list;
        mergedPoint = list;
      } else {
        mergedPoint->next = list;
        if (minHeap.empty()) {
          break;
        }
        mergedPoint = mergedPoint->next;
      }

      list = list->next;
      int minNow = minHeap.top()->val;

      while (list != nullptr && list->val <= minNow) {
        mergedPoint->next = list;
        mergedPoint = mergedPoint->next;
        list = list->next;
      }
      if (list != nullptr) {
        minHeap.push(list);
      }
    }

    return merged;
  }
};

}  // namespace leetcode_23