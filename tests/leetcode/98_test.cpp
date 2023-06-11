// Unit tests for LeetCode Solution 98
#include "../../src/leetcode/98.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode98 : public testing::TestWithParam<std::tuple<std::vector<int>, bool>> {
 protected:
  leetcode_98::Solution solution;
  LeetCode98() {
  }
  ~LeetCode98() override {
  }
  void SetUp() override {
    std::vector<int> vals;
    std::tie(vals, valid) = GetParam();
    root = createBTree(vals);
  }
  void TearDown() override {
    freeTreeNodes(root);
  }

  bool valid;
  TreeNode* root;
};

// test_suite_name, test_name
TEST_P(LeetCode98, Test) {
  bool actual = solution.isValidBST(root);
  ASSERT_EQ(valid, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode98,
    testing::Values(std::make_tuple(std::vector<int>{-2147483648, NULL_NODE_VAL, 2147483647}, true),
                    std::make_tuple(std::vector<int>{2, 1, 3}, true),
                    std::make_tuple(std::vector<int>{5, 1, 4, NULL_NODE_VAL, NULL_NODE_VAL, 3, 6}, false),
                    std::make_tuple(std::vector<int>{120, 70, 140, 50, 100, 130, 160, 20, 55, 75, 110, 119, 135, 150,
                                                     200},
                                    false)));
}  // namespace