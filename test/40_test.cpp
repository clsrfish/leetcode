// Unit tests for LeetCode Solution 40
#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

#include "../src/40.cpp"

namespace {
class LeetCode40
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<std::vector<int>>>> {
protected:
  leetcode_40::Solution solution;
  LeetCode40() {}
  ~LeetCode40() override {}
  void SetUp() override { std::tie(candidates, target, expected) = GetParam(); }
  void TearDown() override {}
  std::vector<int> candidates;
  int target;
  std::vector<std::vector<int>> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode40, Test) {
  auto actual = solution.combinationSum2(candidates, target);
  ASSERT_EQ(expected, actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode40,
    testing::Values(std::make_tuple(std::vector<int>{10, 1, 2, 7, 6, 1, 5}, 8,
                                    // 1, 1, 2, 5, 6, 7, 10
                                    std::vector<std::vector<int>>{
                                        {1, 1, 6},
                                        {1, 2, 5},
                                        {1, 7},
                                        {2, 6},
                                    }),
                    std::make_tuple(std::vector<int>{2, 5, 2, 1, 2}, 5,
                                    // 1, 2, 2, 2, 5
                                    std::vector<std::vector<int>>{
                                        {1, 2, 2},
                                        {5},
                                    })));
} // namespace