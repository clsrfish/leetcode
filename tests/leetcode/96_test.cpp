// Unit tests for LeetCode Solution 96
#include "../../src/leetcode/96.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCodeSuite_96 : public testing::TestWithParam<std::tuple<int, int>> {
 protected:
  leetcode_96::Solution solution;
  LeetCodeSuite_96() {
  }

  ~LeetCodeSuite_96() override {
  }

  void SetUp() override {
    std::tie(n, expected) = GetParam();
  }

  void TearDown() override {
  }

  int n;
  int expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_96, Test) {
  int actual = solution.numTrees(n);

  ASSERT_EQ(expected, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_96,
                         testing::Values(std::make_tuple(3, 5), std::make_tuple(1, 1), std::make_tuple(18, 477638700)));
}  // namespace