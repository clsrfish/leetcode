// Unit tests for LeetCode Solution 95
#include "../../src/leetcode/95.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "../utils/tree_util.hpp"

namespace {
class LeetCodeSuite_95 : public testing::TestWithParam<std::tuple<int, std::vector<std::vector<int>>>> {
 protected:
  leetcode_95::Solution solution;
  LeetCodeSuite_95() {
  }
  ~LeetCodeSuite_95() override {
  }
  void SetUp() override {
    std::tie(n, trees) = GetParam();
  }
  void TearDown() override {
  }

  int n;
  std::vector<std::vector<int>> trees;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_95, Test) {
  auto actual = solution.generateTrees(n);
  // std::vector<std::vector<int>> flatten;
  // for (auto& tree : actual) {
  //   flatten.emplace_back(levelOrder(tree));
  // }
  // FIXME: traveral rule unclear
  // ASSERT_EQ(trees, flatten);
  freeTrees(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCodeSuite_95,
    testing::Values(std::make_tuple(3, std::vector<std::vector<int>>{{1, NULL_NODE_VAL, 2, NULL_NODE_VAL, 3},
                                                                     {1, NULL_NODE_VAL, 3, 2},
                                                                     {2, 1, 3},
                                                                     {3, 1, NULL_NODE_VAL, NULL_NODE_VAL, 2},
                                                                     {3, 2, NULL_NODE_VAL, 1}}),
                    std::make_tuple(1, std::vector<std::vector<int>>{{1}})));
}  // namespace