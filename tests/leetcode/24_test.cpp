#include "../../src/leetcode/24.cpp"

#include <gtest/gtest.h>

namespace
{
class LeetCodeSuite_24 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  LeetCodeSuite_24() {
  }
  ~LeetCodeSuite_24() override {
  }
  void SetUp() override {
    std::vector<int> input;
    std::tie(input, expected) = GetParam();
    this->list = ListNode::fromVector(input);
  }
  void TearDown() override {
  }

  ListNode *list;
  std::vector<int> expected;
};

  // test_suite_name, test_name
TEST_P(LeetCodeSuite_24, swapPairs) {
  leetcode_24::Solution solution;
  auto actual = solution.swapPairs(this->list);
  auto vec = ListNode::toVector(actual);
  ASSERT_EQ(expected, vec);
  ListNode::free(actual);
}

  TEST_P(LeetCodeSuite_24, swapPairsRecursively) {
    leetcode_24::Solution2 solution;
    auto actual = solution.swapPairsRecursively(this->list);
    auto vec = ListNode::toVector(actual);
    ASSERT_EQ(expected, vec);
    ListNode::free(actual);
  }

  // prefix, test_suite_name
  INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_24,
                           testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 4, 5},
                                                           std::vector<int>{2, 1, 4, 3, 5})));
}