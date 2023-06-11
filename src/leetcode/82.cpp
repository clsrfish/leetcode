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
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../model/list_node.hpp"

namespace leetcode_82
{
  class Solution
  {
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
      if (head == nullptr)
      {
        return nullptr;
      }
      ListNode *newHead = nullptr, *newTail = nullptr;
      ListNode *current = head, *probe = nullptr;
      while (current != nullptr)
      {
        int count = 1;
        probe = current->next;
        while (probe != nullptr && probe->val == current->val)
        {
          probe = probe->next;
          count++;
        }
        if (count == 1)
        {
          if (newHead == nullptr)
          {
            newHead = current;
            newTail = current;
          }
          else
          {
            newTail->next = current;
            newTail = current;
          }
        }
        else
        {
          while (count-- > 0)
          {
            auto tmp = current;
            current = current->next;
            delete tmp;
          }
        }

        current = probe;
      }

      if (newTail != nullptr)
      {
        newTail->next = nullptr;
      }
      return newHead;
    }
  };
} // namespace leetcode_82
