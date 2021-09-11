// Unit tests for LeetCode Solution 104
#include "../src/104.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "./utils/tree_util.hpp"

namespace {
class LeetCode104 : public testing::TestWithParam<std::tuple<std::vector<int>, int>> {
 protected:
  leetcode_104::Solution solution;
  LeetCode104() {
  }
  ~LeetCode104() override {
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
  int expected;
};

// test_suite_name, test_name
TEST_P(LeetCode104, Test) {
  int actual = solution.maxDepth(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode104,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7}, 3)));
}  // namespace