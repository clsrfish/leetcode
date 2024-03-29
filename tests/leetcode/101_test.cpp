// Unit tests for LeetCode Solution 101
#include "../../src/leetcode/101.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../../src/model/tree_node.hpp"
#include "../utils/tree_util.hpp"

namespace {
class LeetCode101 : public testing::TestWithParam<std::tuple<std::vector<int>, bool>> {
 protected:
  leetcode_101::Solution solution;
  leetcode_101::Solution2 solution2;
  LeetCode101() {
  }
  ~LeetCode101() override {
  }
  void SetUp() override {
    std::vector<int> nodes;
    std::tie(nodes, expected) = GetParam();
    root = createBTree(nodes);
  }
  void TearDown() override {
    freeTreeNodes(root);
  }

  TreeNode *root;
  bool expected;
};

// test_suite_name, test_name
TEST_P(LeetCode101, Test) {
  bool actual = solution.isSymmetric(root);
  ASSERT_EQ(actual, expected);
}

TEST_P(LeetCode101, TestIteratively) {
  bool actual = solution2.isSymmetric(root);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCode101,
    testing::Values(std::make_tuple(std::vector<int>({1, 2, 2, 3, 4, 4, 3}), true),
                    std::make_tuple(std::vector<int>({1, 2, 2, NULL_NODE_VAL, 3, NULL_NODE_VAL, 3}), false)));
}  // namespace