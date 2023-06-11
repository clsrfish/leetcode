/**
 * @file 0021.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 合并两个有序链表.
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * @version 0.1
 * @date 2021-01-17
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <tuple>
#include <vector>

#include "../model/list_node.hpp"
#include "../utils/stl_utils.hpp"

namespace leetcode_0021 {
std::string key = "0021";
class Solution {
public:
  // merge in loop, and merge recursively with max stack depth 1.
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    } else if (l1 == nullptr || l2 == nullptr) {
      return l1 == nullptr ? l2 : l1;
    } else {
      ListNode *head, *node = nullptr;
      while (l1 != nullptr && l2 != nullptr) {
        int val1 = l1->val;
        int val2 = l2->val;
        if (node == nullptr) {
          head = node = val1 <= val2 ? l1 : l2;
        } else {
          node->next = val1 <= val2 ? l1 : l2;
          node = node->next;
        }
        if (val1 <= val2) {
          l1 = l1->next;
        } else {
          l2 = l2->next;
        }
      }
      node->next = mergeTwoLists(l1, l2);
      return head;
    }
  }

  // merge recursively, but may cause stack-overflow
  ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    } else if (l1 == nullptr || l2 == nullptr) {
      return l1 == nullptr ? l2 : l1;
    } else {
      if (l1->val < l2->val) {
        l1->next = mergeTwoLists2(l1->next, l2);
        return l1;
      } else {
        l2->next = mergeTwoLists2(l1, l2->next);
        return l2;
      }
    }
  }
};

int main() {
  std::cout << key << ": 合并两个有序链表" << std::endl;
#define _TEST_CASE_TYPE std::vector<int>, std::vector<int>, std::vector<int>

  std::vector<std::tuple<_TEST_CASE_TYPE>> test_cases = {
      std::make_tuple<_TEST_CASE_TYPE>({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}),
  };
  for (auto &&entry : test_cases) {
    auto input1 = std::get<0>(entry);
    auto input2 = std::get<1>(entry);
    auto expected = std::get<2>(entry);

    ListNode *l1 = nullptr, *l2 = nullptr, *node = nullptr;
    for (auto &&i : input1) {
      if (l1 == nullptr) {
        node = new ListNode(i);
        l1 = node;
      } else {
        node->next = new ListNode(i);
        node = node->next;
      }
    }
    for (auto &&i : input2) {
      if (l2 == nullptr) {
        node = new ListNode(i);
        l2 = node;
      } else {
        node->next = new ListNode(i);
        node = node->next;
      }
    }

    auto output = Solution().mergeTwoLists(l1, l2);
    std::vector<int> output_v;
    while (output != nullptr) {
      output_v.push_back(output->val);
      output = output->next;
    }

    std::cout << "l1:" << vector2str(input1) << " l2:" << vector2str(input2) << " expected:" << vector2str(expected)
              << " output:" << vector2str(output_v) << std::endl;
  }

  return 0;
}
} // namespace leetcode_0021