// Unit tests for LeetCode Solution 112
#include "../../src/leetcode/112.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode112 : public testing::TestWithParam<std::tuple<std::vector<int>, int, bool>> {
 protected:
  leetcode_112::Solution solution;
  LeetCode112() {
  }
  ~LeetCode112() override {
  }
  void SetUp() override {
    std::vector<int> tmp;
    std::tie(tmp, targetSum, expected) = GetParam();
    root = createBTree(tmp);
  }
  void TearDown() override {
    freeTreeNodes(root);
  }

  TreeNode* root = nullptr;
  int targetSum;
  bool expected;
};

// test_suite_name, test_name
TEST_P(LeetCode112, Test) {
  bool actual = solution.hasPathSum(root, targetSum);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode112,
    testing::Values(std::make_tuple(std::vector<int>{5, 4, 8, 11, NULL_NODE_VAL, 13, 4, 7, 2, NULL_NODE_VAL,
                                                     NULL_NODE_VAL, NULL_NODE_VAL, 1},
                                    22, true),
                    std::make_tuple(std::vector<int>{1, 2, 3}, 5, false),
                    std::make_tuple(std::vector<int>{1, 2}, 0, false), std::make_tuple(std::vector<int>{}, 0, false)));
}  // namespace