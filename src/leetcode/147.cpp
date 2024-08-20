#include <iostream>
#include <string>
#include <vector>

#include "../model/list_node.hpp"

namespace leetcode_147 {
class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    auto tail = head;
    while (true) {
      while (tail->next != nullptr && tail->next->val >= tail->val) {
        tail = tail->next;
      }
      auto pickup = removeNextFromList(tail);
      if (pickup == nullptr) {
        break;
      }

      head = insertIntoList(head, pickup);
    }

    return head;
  }

 private:
  ListNode* removeNextFromList(ListNode* tail) {
    if (tail == nullptr || tail->next == nullptr) {
      return nullptr;
    }

    auto node = tail->next;
    tail->next = node->next;
    node->next = nullptr;
    return node;
  }

  ListNode* insertIntoList(ListNode* head, ListNode* node) {
    ListNode *predecessor = nullptr, *successor = head;
    while (successor->val <= node->val && successor != node) {
      predecessor = successor;
      successor = successor->next;
    }
    node->next = successor;
    if (predecessor != nullptr) {
      predecessor->next = node;
    } else {
      return node;
    }

    return head;
  }
};
}  // namespace leetcode_147
