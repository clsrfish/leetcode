// Unit tests for LeetCode Solution 83
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

#include "../../src/leetcode/83.cpp"

namespace {
class LeetCodeSuite_83 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_83::Solution solution;
  LeetCodeSuite_83() {
  }
  ~LeetCodeSuite_83() override {
    ListNode::free(list);
  }
  void SetUp() override {
    std::vector<int> nodes;
    std::tie(nodes, expected) = GetParam();
    list = ListNode::fromVector(nodes);
  }
  void TearDown() override {}
  ListNode *list;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_83, Test) {
  auto actual = solution.deleteDuplicates(list);
  auto actualVec = ListNode::toVector(actual);
  ASSERT_EQ(expected, actualVec);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_83,
                         testing::Values(std::make_tuple(std::vector<int>{1, 1, 2}, std::vector<int>{1, 2}),
                                         std::make_tuple(std::vector<int>{1, 1, 2, 3, 3}, std::vector<int>{1, 2, 3})));
} // namespace