#include "../../src/leetcode/23.cpp"

#include <gtest/gtest.h>

namespace
{
class LeetCodeSuite_23 : public testing::TestWithParam<std::tuple<std::vector<std::vector<int>>, std::vector<int>>> {
 protected:
  leetcode_23::Solution solution;
  LeetCodeSuite_23() {
  }
  ~LeetCodeSuite_23() override {
  }
  void SetUp() override {
    std::vector<std::vector<int>> input;
    std::tie(input, expected) = GetParam();
    for (auto &&vec : input) {
      this->lists.push_back(ListNode::fromVector(vec));
    }
  }
  void TearDown() override {
  }

  std::vector<ListNode *> lists;
  std::vector<int> expected;
};

  // test_suite_name, test_name
TEST_P(LeetCodeSuite_23, Test) {
  auto actual = solution.mergeKLists(this->lists);
  auto vec = ListNode::toVector(actual);
  ASSERT_EQ(expected, vec);
  ListNode::free(actual);
}

  // prefix, test_suite_name
  INSTANTIATE_TEST_SUITE_P(
      leetcode, LeetCodeSuite_23,
      testing::Values(std::make_tuple(std::vector<std::vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}, {}},
                                      std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6})));
}