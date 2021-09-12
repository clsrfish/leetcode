// Unit tests for LeetCode Solution 110
#include "../src/110.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "./utils/tree_util.hpp"

namespace {
class LeetCode110 : public testing::TestWithParam<std::tuple<std::vector<int>, bool>> {
 protected:
  leetcode_110::Solution solution;
  LeetCode110() {
  }
  ~LeetCode110() override {
  }
  void SetUp() override {
    std::vector<int> tmp;
    std::tie(tmp, expected) = GetParam();
    root = createBTree(tmp);
  }
  void TearDown() override {
    freeTreeNodes(root);
  }
  TreeNode* root;
  bool expected;
};

// test_suite_name, test_name
TEST_P(LeetCode110, Test) {
  auto actual = solution.isBalanced(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    TestP, LeetCode110,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7}, true),
                    std::make_tuple(std::vector<int>{1, 2, 2, 3, 3, NULL_NODE_VAL, NULL_NODE_VAL, 4, 4}, false),
                    std::make_tuple(std::vector<int>{}, true)));
}  // namespace