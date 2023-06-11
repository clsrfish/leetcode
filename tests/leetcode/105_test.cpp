// Unit tests for LeetCode Solution 105
#include "../../src/leetcode/105.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode105 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_105::Solution solution;
  LeetCode105() {
  }
  ~LeetCode105() override {
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
TEST_P(LeetCode105, Test) {
  auto actual = solution.buildTree(preorder, inorder);
  ASSERT_EQ(true, treeEquals(actual, expected));
  freeTreeNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode105,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, 15, 7}, std::vector<int>{9, 3, 15, 20, 7},
                                    std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7}),
                    std::make_tuple(std::vector<int>{-1}, std::vector<int>{-1}, std::vector<int>{-1})));
}  // namespace