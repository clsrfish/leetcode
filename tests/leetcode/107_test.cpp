// Unit tests for LeetCode Solution 107
#include "../../src/leetcode/107.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode107 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {
 protected:
  leetcode_107::Solution solution;
  LeetCode107() {
  }
  ~LeetCode107() override {
  }
  void SetUp() override {
    std::vector<int> tmp;
    std::tie(tmp, expected) = GetParam();
    root = createBTree(tmp);
  }
  void TearDown() override {
    freeTreeNodes(root);
    root = nullptr;
  }

  TreeNode* root;
  std::vector<std::vector<int>> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode107, Test) {
  auto actual = solution.levelOrderBottom(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCode107,
                         testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15,
                                                                          7},
                                                         std::vector<std::vector<int>>{{15, 7}, {9, 20}, {3}})));
}  // namespace