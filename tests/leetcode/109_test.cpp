// Unit tests for LeetCode Solution 109
#include "../../src/leetcode/109.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_109 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_109::Solution solution;
  LeetCodeSuite_109() {
  }
  ~LeetCodeSuite_109() override {
  }
  void SetUp() override {
    std::vector<int> a, b;
    std::tie(a, b) = GetParam();
    input = ListNode::fromVector(a);
    expected = createBTree(b);
  }
  void TearDown() override {
    freeTreeNodes(expected);
    ListNode::free(input);
  }

  ListNode* input;
  TreeNode* expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_109, TestName) {
  auto actual = solution.sortedListToBST(input);
  ASSERT_EQ(true, treeEquals(actual, expected));
  freeTreeNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_109,
                         testing::Values(std::make_tuple(std::vector<int>{-10, -3, 0, 5, 9},
                                                         std::vector<int>{0, -3, 9, -10, NULL_NODE_VAL, 5})));
}  // namespace