#include "./list_util.hpp"

ListNode *createList(std::vector<int> &nums) {
  if (nums.empty()) {
    return nullptr;
  }

  ListNode *head = new ListNode(nums[0]);
  ListNode *tmp = head;
  for (decltype(nums.size()) i = 1; i < nums.size(); i++) {
    tmp->next = new ListNode(nums[i]);
    tmp = tmp->next;
  }

  return head;
}

std::vector<int> listToVector(ListNode *head) {
  std::vector<int> vec;
  while (head != nullptr) {
    vec.push_back(head->val);
    head = head->next;
  }
  return vec;
}

void freeListNodes(ListNode *list) {
  if (list == nullptr) {
    return;
  }
  freeListNodes(list->next);
  list->next = nullptr;
  delete list;
}
