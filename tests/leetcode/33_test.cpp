// Unit tests for LeetCode Solution 33
#include "../../src/leetcode/33.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCodeSuite_33 : public testing::TestWithParam<std::tuple<std::vector<int>, int, int>> {
 protected:
  leetcode_33::Solution solution;
  leetcode_33::Solution2 solution2;
  LeetCodeSuite_33() {
  }
  ~LeetCodeSuite_33() override {
  }
  void SetUp() override { std::tie(nums, target, expected) = GetParam(); }
  void TearDown() override {}
  std::vector<int> nums;
  int target;
  int expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_33, Test) {
  int actual = solution.search(nums, target);
  ASSERT_EQ(expected, actual);
}

TEST_P(LeetCodeSuite_33, Test2) {
  int actual = solution2.search(nums, target);
  ASSERT_EQ(expected, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_33,
                         testing::Values(std::make_tuple(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 0, 4),
                                         std::make_tuple(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 3, -1),
                                         std::make_tuple(std::vector<int>{1}, 0, -1),
                                         std::make_tuple(std::vector<int>{5, 1, 3}, 3, 2)));

} // namespace