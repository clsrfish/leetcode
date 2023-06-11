// Unit tests for LeetCode Solution 39
#include "../../src/leetcode/39.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode39
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>> {
protected:
  leetcode_39::Solution solution;
  LeetCode39() {}
  ~LeetCode39() override {}
  void SetUp() override { std::tie(candidates, target, expected) = GetParam(); }
  void TearDown() override {}

  std::vector<int> candidates;
  int target;
  std::vector<std::vector<int>> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode39, Test) {
  auto actual = solution.combinationSum(candidates, target);
  ASSERT_EQ(expected, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode39,
    testing::Values(std::make_tuple(std::vector<int>{2, 3, 6, 7}, 7,
                                    std::vector<std::vector<int>>{{2, 2, 3},
                                                                  {7}}),
                    std::make_tuple(std::vector<int>{2, 3, 5}, 8,
                                    std::vector<std::vector<int>>{
                                        {2, 2, 2, 2}, {2, 3, 3}, {3, 5}}),
                    std::make_tuple(std::vector<int>{2}, 1,
                                    std::vector<std::vector<int>>{}),
                    std::make_tuple(std::vector<int>{1}, 1,
                                    std::vector<std::vector<int>>{{1}}),
                    std::make_tuple(std::vector<int>{1}, 2,
                                    std::vector<std::vector<int>>{{1, 1}})));
} // namespace