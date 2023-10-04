#include "../../src/leetcode/28.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>

namespace {
class LeetCode28 : public testing::TestWithParam<std::tuple<std::string, std::string, int>> {
 protected:
  leetcode_28::Solution solution;
  LeetCode28(/* args */) {
  }
  ~LeetCode28() override {
  }

  void SetUp() override {
  }

  void TearDown() override {
  }
};

TEST_P(LeetCode28, Test) {
  std::string haystack, needle;
  int expected;
  std::tie(haystack, needle, expected) = GetParam();

  int index = solution.strStr(haystack, needle);
  ASSERT_EQ(index, expected);
}

INSTANTIATE_TEST_SUITE_P(leetcode, LeetCode28,
                         testing::Values(std::make_tuple("hello", "ll", 2), std::make_tuple("hello", "lol", -1),
                                         std::make_tuple("123", "1234", -1), std::make_tuple("", "", 0)));
}  // namespace
