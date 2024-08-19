#include "./list_node.hpp"

ListNode *ListNode::fromVector(const std::vector<int> &source) {
  if (source.empty()) {
    return nullptr;
  }

  ListNode *head = nullptr;
  ListNode *node = nullptr;

  for (auto &&i : source) {
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

std::vector<int> ListNode::toVector(ListNode *head) {
  std::vector<int> res;
  while (head != nullptr) {
    res.push_back(head->val);
    head = head->next;
  }
  return res;
}

void ListNode::free(ListNode *head) {
  if (head == nullptr) {
    return;
  }
  ListNode::free(head->next);
  head->next = nullptr;
  delete head;
}

void ListNode::print(const ListNode *node) {
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