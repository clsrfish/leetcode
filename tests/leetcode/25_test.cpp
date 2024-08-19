#include "../../src/leetcode/25.cpp"

#include <gtest/gtest.h>

namespace
{
class LeetCodeSuite_25 : public testing::TestWithParam<std::tuple<std::vector<int>, int, std::vector<int>>> {
 protected:
  leetcode_25::Solution solution;
  LeetCodeSuite_25() {
  }
  ~LeetCodeSuite_25() override {
  }
  void SetUp() override {
    std::vector<int> input;
    std::tie(input, this->k, this->expected) = GetParam();
    list = ListNode::fromVector(input);
  }
  void TearDown() override {
  }

  ListNode *list;
  int k;
  std::vector<int> expected;
};

  // test_suite_name, test_name
TEST_P(LeetCodeSuite_25, Test) {
  auto actual = solution.reverseKGroup(this->list, this->k);
  auto vec = ListNode::toVector(actual);
  ASSERT_EQ(expected, vec);
  ListNode::free(actual);
}

  // prefix, test_suite_name
  INSTANTIATE_TEST_SUITE_P(leetcode, LeetCodeSuite_25,
                           testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 3,
                                                           std::vector<int>{3, 2, 1, 4, 5})));
}
