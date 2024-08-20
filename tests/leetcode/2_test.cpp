// Unit tests for LeetCode Solution 2

#include "../../src/leetcode/2.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {

class LeetCodeSuite_2
    : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_2::Solution solution;
  LeetCodeSuite_2() {
  }
  ~LeetCodeSuite_2() override {
  }
  void SetUp() override {
    std::vector<int> v1, v2;
    std::tie(v1, v2, expected) = GetParam();

    l1 = ListNode::fromVector(v1);
    l2 = ListNode::fromVector(v2);
  }
  void TearDown() override {
    ListNode::free(l1);
    ListNode::free(l2);
  }

  ListNode* l1 = nullptr;
  ListNode* l2 = nullptr;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_2, Test) {
  auto actual = solution.addTwoNumbers(l1, l2);

  ASSERT_EQ(expected, ListNode::toVector(actual));

  ListNode::free(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_2,
                         testing::Values(std::make_tuple(std::vector<int>({2, 4, 3}), std::vector<int>({5, 6, 4}),
                                                         std::vector<int>({7, 0, 8}))));

}  // namespace