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
#include <iostream>
#include <vector>
class ListNode {
 public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }

  /**
   * @brief Create a List Nodes From Vec object
   *
   * @param source
   * @return ListNode*
   */
  static ListNode *fromVector(const std::vector<int> &source);
  /**
   * @brief Convert List Nodes to vector.
   *
   * @param head
   * @return std::vector<int>
   */
  static std::vector<int> toVector(ListNode *head);
  static void free(ListNode *head);
  static void print(const ListNode *head);
};

#endif