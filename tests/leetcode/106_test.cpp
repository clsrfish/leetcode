// Unit tests for LeetCode Solution 106
#include "../../src/leetcode/106.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCode106 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_106::Solution solution;
  LeetCode106() {
  }
  ~LeetCode106() override {
  }
  void SetUp() override {
    std::vector<int> tmp;
    std::tie(inorder, postorder, tmp) = GetParam();
    expected = createBTree(tmp);
  }
  void TearDown() override {
    freeTreeNodes(expected);

    expected = nullptr;
  }
  std::vector<int> inorder;
  std::vector<int> postorder;
  TreeNode* expected;
};

// test_suite_name, test_name
TEST_P(LeetCode106, Test) {
  auto actual = solution.buildTree(inorder, postorder);
  ASSERT_EQ(true, treeEquals(actual, expected));
  freeTreeNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCode106,
    testing::Values(std::make_tuple(std::vector<int>{9, 3, 15, 20, 7}, std::vector<int>{9, 15, 7, 20, 3},
                                    std::vector<int>{3, 9, 20, NULL_NODE_VAL, NULL_NODE_VAL, 15, 7})));
}  // namespace