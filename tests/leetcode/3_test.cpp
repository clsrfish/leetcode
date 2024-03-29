// Unit tests for LeetCode Solution 3
#include "../../src/leetcode/3.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace {
class LeetCode3 : public testing::TestWithParam<std::tuple<std::string, int>> {
 protected:
  leetcode_3::Solution markSolution;
  leetcode_3::Solution2 slideWinSolution;
  LeetCode3() {
  }
  ~LeetCode3() override {
  }
  void SetUp() override {
    std::tie(s, expected) = GetParam();
  }
  void TearDown() override {
  }

  std::string s;
  int expected;
};

// test_suite_name, test_name
TEST_P(LeetCode3, TestMarks) {
  int actual = markSolution.lengthOfLongestSubstring(s);
  ASSERT_EQ(actual, expected);
}

TEST_P(LeetCode3, TestSlideWindow) {
  int actual = slideWinSolution.lengthOfLongestSubstring(s);
  ASSERT_EQ(actual, expected);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(leetcode, LeetCode3,
                         testing::Values(std::make_tuple("abcabcbb", 3), std::make_tuple("bbbbb", 1),
                                         std::make_tuple("pwwkew", 3), std::make_tuple("   ", 1)));
}  // namespace