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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
  }
};

/**
 * @brief Create a List Nodes From Vec object
 *
 * @param inputs
 * @return ListNode*
 */
ListNode *createListNodesFromVec(const std::vector<int> &inputs) {
  if (inputs.empty()) {
    return nullptr;
  }

  ListNode *head = nullptr;
  ListNode *node = nullptr;

  for (auto &&i : inputs) {
    if (head == nullptr) {
      head = new ListNode(i);
      node = head;
    } else {
      node->next = new ListNode(i);
      node = node->next;
    }
  }
  return head;
}

/**
 * @brief print List string.
 *
 * @param node
 */
void printListNodes(const ListNode *node) {
  std::cout << '[';
  while (node != nullptr) {
    std::cout << node->val;
    node = node->next;
    if (node != nullptr) {
      std::cout << ", ";
    }
  }
  std::cout << ']' << std::endl;
}

#endif