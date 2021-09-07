// Unit tests for LeetCode Solution 99
#include "../src/99.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "./utils/tree_util.hpp"

namespace {
class LeetCode99 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_99::Solution solution;
  LeetCode99() {
  }
  ~LeetCode99() override {
  }
  void SetUp() override {
    std::vector<int> input, output;
    std::tie(input, output) = GetParam();
    root = createBTree(input);
    rootNew = createBTree(output);
  }
  void TearDown() override {
    freeTreeNodes(root);
    root = nullptr;
    freeTreeNodes(rootNew);
    rootNew = nullptr;
  }

  TreeNode* root;
  TreeNode* rootNew;
};

// test_suite_name, test_name
TEST_P(LeetCode99, Test) {
  solution.recoverTree(root);

  ASSERT_EQ(true, treeEquals(root, rootNew));
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(TestP, LeetCode99,
                         testing::Values(std::make_tuple(std::vector<int>{1, 3, NULL_NODE_VAL, NULL_NODE_VAL, 2},
                                                         std::vector<int>{3, 1, NULL_NODE_VAL, NULL_NODE_VAL, 2})));
}  // namespace