// Unit tests for LeetCode Solution 113
#include "../../src/leetcode/113.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode113 : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>> {
 protected:
  leetcode_113::Solution solution;
  LeetCode113() {
  }
  ~LeetCode113() override {
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
  std::vector<std::vector<int>> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode113, Test) {
  auto actual = solution.pathSum(root, targetSum);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCode113,
    testing::Values(std::make_tuple(std::vector<int>{5, 4, 8, 11, NULL_NODE_VAL, 13, 4, 7, 2, NULL_NODE_VAL,
                                                     NULL_NODE_VAL, NULL_NODE_VAL, NULL_NODE_VAL, 5, 1},
                                    22, std::vector<std::vector<int>>{{5, 4, 11, 2}, {5, 8, 4, 5}}),
                    std::make_tuple(std::vector<int>{1, 2, 3}, 5, std::vector<std::vector<int>>{}),
                    std::make_tuple(std::vector<int>{1, 2}, 0, std::vector<std::vector<int>>{}),
                    std::make_tuple(std::vector<int>{}, 0, std::vector<std::vector<int>>{})));
}  // namespace