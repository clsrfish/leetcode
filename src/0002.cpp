/**
 * 两数相加
 */
#include <iostream>
using namespace std;
namespace leetcode_0002 {
string key = "0002";
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

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
int main() {
  std::cout << key << ":两数相加" << std::endl;
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  ListNode *result = Solution().addTwoNumbers(l1, l2);

  while (result != nullptr) {
    cout << result->val;
    result = result->next;
  }
  cout << endl;
  return 0;
}

} // namespace leetcode_0002