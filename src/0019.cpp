/**
 * @file 0019.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 删除链表的倒数第N个节点.
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * @version 0.1
 * @date 2021-01-16
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <vector>

namespace leetcode_0019 {
std::string key = "0019";

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (n == 0) {
      return head;
    }

    ListNode *fast = head;
    int i = 0;
    while (i++ < n) {
      fast = fast->next;
    }
    if (fast == nullptr) {
      return head->next;
    }
    ListNode *slow = head;
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;

    return head;
  }
};
int main() {
  std::cout << key << ": 删除链表的倒数第N个节点" << std::endl;

  std::vector<int> nums = {1, 2, 3, 4, 5};
  int n = 0;
  ListNode *node, *head;
  for (auto &&i : nums) {
    if (node == nullptr) {
      node = head = new ListNode(i);
    } else {
      node->next = new ListNode(i);
      node = node->next;
    }
  }

  ListNode *new_head = Solution().removeNthFromEnd(head, n);
  auto pos = nums.begin() + (nums.size() - n);
  if (pos != nums.end()) {
    nums.erase(pos);
  }
  std::cout << "expected:";
  for (auto &&i : nums) {
    std::cout << i << ',';
  }
  std::cout << std::endl;

  std::cout << "result  :";
  while (new_head != nullptr) {
    std::cout << new_head->val << ',';
    new_head = new_head->next;
  }
  std::cout << std::endl;

  return 0;
}
} // namespace leetcode_0019