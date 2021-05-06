// Unit tests for LeetCode Solution 100
#include "../src/100.cpp"
#include "./utils/tree_util.hpp"
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode100 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>, bool>> {
protected:
  leetcode_100::Solution solution;
  LeetCode100() {
  }
  ~LeetCode100() override {
  }
  void SetUp() override {
    std::vector<int> pHeap, qHeap;
    std::tie(pHeap, qHeap, expected) = GetParam();
    p = createBTree(pHeap);
    q = createBTree(qHeap);
  }
  void TearDown() override {
  }
  TreeNode *p = nullptr, *q = nullptr;
  bool expected;
};

// test_suite_name, test_name
TEST_P(LeetCode100, Test) {
  bool actual = solution.isSameTree(p, q);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode100,
    testing::Values(std::make_tuple(std::vector<int>({1, 2, 3}), std::vector<int>({1, 2, 3}), true),
                    std::make_tuple(std::vector<int>({1, 2}), std::vector<int>({1, NULL_NODE_VAL, 2}), false),
                    std::make_tuple(std::vector<int>({1, 2, 1}), std::vector<int>({1, 1, 2}), false)));
} // namespace