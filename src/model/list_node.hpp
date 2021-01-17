/**
 * @file list_node.hpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 链表节点
 * @version 0.1
 * @date 2021-01-17
 *
 * @copyright Copyright (c) 2021
 *
 */
#if !defined(LIST_NODE_H)
#define LIST_NODE_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr) {
  }
  ListNode(int x)
      : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next)
      : val(x), next(next) {
  }
};

#endif