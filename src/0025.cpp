/**
 * @file 0025.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief K 个一组翻转链 https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
 * @version 0.1
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

#include "./model/list_node.hpp"
#include "./utils/stl_utils.hpp"

namespace leetcode_0025 {
std::string key = "0025";
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    return reverseFirstKGroup(head, k, lengthOfListNode(head));
  }

 private:
  int lengthOfListNode(ListNode* head) {
    if (head == nullptr) {
      return 0;
    }
    int length = 1;
    while (head->next != nullptr) {
      head = head->next;
      length++;
    }

    return length;
  }
  ListNode* reverseFirstKGroup(ListNode* head, int k, int remain) {
    if (remain < k) {
      return head;
    }

    ListNode* originHead = head;

    ListNode* preNode = nullptr;
    for (int i = 0; i < k; i++) {
      auto next = head->next;
      if (preNode != nullptr) {
        head->next = preNode;
      }
      preNode = head;

      head = next;
    }

    originHead->next = reverseFirstKGroup(head, k, remain - k);
    return preNode;
  }
};
int main() {
  std::cout << key << ": K 个一组翻转链表" << std::endl;

  int k = 3;
  auto list = createListNodesFromVec(std::vector<int>({1, 2, 3, 4, 5}));
  auto res = Solution().reverseKGroup(list, k);
  printListNodes(res);
  return 0;
}
}  // namespace leetcode_0025