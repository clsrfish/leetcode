#include "./list_node.hpp"

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

std::vector<int> listNodes2Vec(ListNode *list) {
  std::vector<int> res;
  while (list != nullptr) {
    res.push_back(list->val);
    list = list->next;
  }
  return res;
}

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