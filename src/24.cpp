/**
 * @file 0024.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief 两两交换链表中的节点 https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * @version 0.1
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <vector>

#include "./model/list_node.hpp"

namespace leetcode_0024 {
std::string key = "0024";
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    // create a fake head node
    ListNode *newHead = new ListNode(0);
    ListNode *tail = newHead;

    while (head != nullptr && head->next != nullptr) {
      auto next = head->next;
      tail->next = next;

      // may be nullptr
      auto next2 = next->next;
      head->next = next2;
      next->next = head;

      // move head forward
      tail = head;
      head = next2;
    }

    tail->next = head;

    return newHead->next;
  }

  /**
   * @brief swap recursively
   *
   * @param head
   * @return ListNode*
   */
  ListNode *swapPairsRecursively(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // next becomes the new head
    auto next = head->next;
    auto next2 = next->next;

    next->next = head;
    head->next = swapPairsRecursively(next2);

    return next;
  }
};
int main() {
  std::cout << key << ": 两两交换链表中的节点" << std::endl;

  ListNode *list = createListNodesFromVec(std::vector<int>({1, 2, 3, 4, 5}));
  auto res = Solution().swapPairsRecursively(list);
  printListNodes(res);
  return 0;
}
} // namespace leetcode_0024