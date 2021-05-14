// Unit tests for LeetCode Solution 103
#include "../src/103.cpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <tuple>
#include <vector>

#include "./utils/tree_util.hpp"

namespace {
class LeetCode103 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {
 protected:
  leetcode_103::Solution solution;
  LeetCode103() {
  }
  ~LeetCode103() override {
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
TEST_P(LeetCode103, Test) {
  auto actual = solution.zigzagLevelOrder(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(P, LeetCode103,
                         testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15,
                                                                          7},
                                                         std::vector<std::vector<int>>{{3}, {20, 9}, {15, 7}})));
}  // namespace