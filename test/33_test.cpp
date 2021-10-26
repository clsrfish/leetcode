// Unit tests for LeetCode Solution 33
#include "../src/33.cpp"

#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode33
    : public testing::TestWithParam<std::tuple<std::vector<int>, int, int>> {
protected:
  leetcode_33::Solution solution;
  leetcode_33::Solution2 solution2;
  LeetCode33() {}
  ~LeetCode33() override {}
  void SetUp() override { std::tie(nums, target, expected) = GetParam(); }
  void TearDown() override {}
  std::vector<int> nums;
  int target;
  int expected;
};

// test_suite_name, test_name
TEST_P(LeetCode33, Test) {
  int actual = solution.search(nums, target);
  ASSERT_EQ(expected, actual);
}

TEST_P(LeetCode33, Test2) {
  int actual = solution2.search(nums, target);
  ASSERT_EQ(expected, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode33,
    testing::Values(
        std::make_tuple(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 0, 4),
        std::make_tuple(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 3, -1),
        std::make_tuple(std::vector<int>{1}, 0, -1),
        std::make_tuple(std::vector<int>{5, 1, 3}, 3, 2)));

} // namespace