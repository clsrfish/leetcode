// Unit tests for LeetCode Solution 108
#include "../../src/leetcode/108.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_108 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_108::Solution solution;
  LeetCodeSuite_108() {
  }
  ~LeetCodeSuite_108() override {
  }
  void SetUp() override {
    std::vector<int> tmp;
    std::tie(input, tmp) = GetParam();
    expected = createBTree(tmp);
  }
  void TearDown() override {
    freeTreeNodes(expected);
    expected = nullptr;
  }
  std::vector<int> input;
  TreeNode* expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_108, Test) {
  auto actual = solution.sortedArrayToBST(input);
  ASSERT_EQ(true, treeEquals(actual, expected));
  freeTreeNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_108,
                         testing::Values(std::make_tuple(std::vector<int>{-10, -3, 0, 5, 9},
                                                         std::vector<int>{0, -3, 9, -10, NULL_NODE_VAL, 5})));
}  // namespace