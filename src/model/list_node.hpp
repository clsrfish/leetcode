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
ListNode *createListNodesFromVec(const std::vector<int> &inputs);

/**
 * @brief Convert List Nodes to vector.
 *
 * @param list
 * @return std::vector<int>
 */
std::vector<int> listNodes2Vec(ListNode *list);

/**
 * @brief print List string.
 *
 * @param node
 */
void printListNodes(const ListNode *node);

#endif