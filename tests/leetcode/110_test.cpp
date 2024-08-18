// Unit tests for LeetCode Solution 110
#include "../../src/leetcode/110.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_110 : public testing::TestWithParam<std::tuple<std::vector<int>, bool>> {
 protected:
  leetcode_110::Solution solution;
  LeetCodeSuite_110() {
  }
  ~LeetCodeSuite_110() override {
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
TEST_P(LeetCodeSuite_110, Test) {
  auto actual = solution.isBalanced(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCodeSuite_110,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7}, true),
                    std::make_tuple(std::vector<int>{1, 2, 2, 3, 3, NULL_NODE_VAL, NULL_NODE_VAL, 4, 4}, false),
                    std::make_tuple(std::vector<int>{}, true)));
}  // namespace