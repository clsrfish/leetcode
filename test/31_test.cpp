// Unit tests for LeetCode Solution 31
#include "../src/31.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode31 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  leetcode_31::Solution solution;
  LeetCode31() {
  }
  ~LeetCode31() override {
  }
  void SetUp() override {
    std::tie(nums, expected) = GetParam();
  }
  void TearDown() override {
  }

  std::vector<int> nums;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode31, Test) {
  solution.nextPermutation(nums);
  ASSERT_EQ(nums, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(TestP, LeetCode31,
                         testing::Values(
                             //  std::make_tuple(std::vector<int>{1, 2, 3}, std::vector<int>{1, 3, 2}),
                             //                std::make_tuple(std::vector<int>{3, 2, 1}, std::vector<int>{1, 2, 3}),
                             //                std::make_tuple(std::vector<int>{1, 1, 5}, std::vector<int>{1, 5, 1}),
                             //                std::make_tuple(std::vector<int>{1}, std::vector<int>{1}),
                             //                std::make_tuple(std::vector<int>{1, 3, 2}, std::vector<int>{2, 1, 3}),
                             std::make_tuple(std::vector<int>{2, 3, 1}, std::vector<int>{3, 1, 2})));
}  // namespace