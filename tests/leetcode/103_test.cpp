// Unit tests for LeetCode Solution 103
#include "../../src/leetcode/103.cpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_103 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {
 protected:
  leetcode_103::Solution solution;
  LeetCodeSuite_103() {
  }
  ~LeetCodeSuite_103() override {
  }
  void SetUp() override {
    std::vector<int> nodes;
    std::tie(nodes, expected) = GetParam();
    root = createBTree(nodes);
  }
  void TearDown() override {
    freeTreeNodes(root);
  }
  TreeNode *root;
  std::vector<std::vector<int>> expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_103, Test) {
  auto actual = solution.zigzagLevelOrder(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_103,
                         testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15,
                                                                          7},
                                                         std::vector<std::vector<int>>{{3}, {20, 9}, {15, 7}})));
}  // namespace