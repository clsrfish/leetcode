// Unit tests for LeetCode Solution 1
#include "../../src/leetcode/1.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode1 : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
 protected:
  leetcode_1::Solution solution;
  LeetCode1() {
  }
  ~LeetCode1() override {
  }
  void SetUp() override {
  }
  void TearDown() override {
  }
};
TEST_P(LeetCode1, Test) {
  std::vector<int> nums, expected;
  int target;
  std::tie(nums, target, expected) = GetParam();
  auto res = solution.twoSum(nums, target);
  ASSERT_EQ(res, expected);
}

INSTANTIATE_TEST_SUITE_P(leetcode, LeetCode1,
                         testing::Values(std::make_tuple(std::vector<int>({2, 7, 11, 15}), 9, std::vector<int>({0, 1})),
                                         std::make_tuple(std::vector<int>({2, 7, 11, 15}), 9,
                                                         std::vector<int>({0, 1}))));
}  // namespace