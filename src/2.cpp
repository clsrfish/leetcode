/**
 * @file 2.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 两数相加 https://leetcode-cn.com/problems/add-two-numbers
 * @version 0.1
 * @date 2021-05-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>

#include "./model/list_node.hpp"

using namespace std;
namespace leetcode_2 {

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int sum = 0;
    ListNode *result = nullptr, *p = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
      sum += l1 != nullptr ? l1->val : 0;
      sum += l2 != nullptr ? l2->val : 0;

      int remain = sum % 10;
      sum /= 10;
      if (p == nullptr) {
        p = new ListNode(remain);
        result = p;
      } else {
        p->next = new ListNode(remain);
        p = p->next;
      }
      l1 = l1 != nullptr ? l1->next : l1;
      l2 = l2 != nullptr ? l2->next : l2;
    }
    if (sum != 0) {
      p->next = new ListNode(sum);
      p->next->next = nullptr;
    }
    return result;
  }
};

}  // namespace leetcode_2