// Unit tests for LeetCode Solution 105
#include "../../src/leetcode/105.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_105
    : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_105::Solution solution;
  LeetCodeSuite_105() {
  }
  ~LeetCodeSuite_105() override {
  }
  void SetUp() override {
    std::vector<int> outputNodes;
    std::tie(preorder, inorder, outputNodes) = GetParam();
    expected = createBTree(outputNodes);
  }
  void TearDown() override {
    freeTreeNodes(expected);

    expected = nullptr;
  }

  std::vector<int> preorder;
  std::vector<int> inorder;
  TreeNode* expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_105, Test) {
  auto actual = solution.buildTree(preorder, inorder);
  ASSERT_EQ(true, treeEquals(actual, expected));
  freeTreeNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCodeSuite_105,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, 15, 7}, std::vector<int>{9, 3, 15, 20, 7},
                                    std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7}),
                    std::make_tuple(std::vector<int>{-1}, std::vector<int>{-1}, std::vector<int>{-1})));
}  // namespace