// Unit tests for LeetCode Solution 147
#include "../src/leetcode/147.cpp"

#include <gtest/gtest.h>

#include <string>
#include <tuple>
#include <vector>

namespace leetcode_147 {
class LeetCodeSuite_147 : public testing::TestWithParam<std::tuple<std::vector<int>, std::vector<int>>> {
 protected:
  LeetCodeSuite_147() {
  }
  ~LeetCodeSuite_147() override {
  }
  void SetUp() override {
    std::tie(input, expected) = GetParam();
  }
  void TearDown() override {
  }
  std::vector<int> input, expected;
};

// test_suite_name, test_name
TEST_P(LeetCodeSuite_147, Test) {
  Solution solution;
  auto head = ListNode::fromVector(this->input);
  auto result = solution.insertionSortList(head);
  ASSERT_EQ(expected, ListNode::toVector(result));

  ListNode::free(result);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    leetcode, LeetCodeSuite_147,
    testing::Values(std::make_tuple(std::vector<int>({4, 2, 1, 3}), std::vector<int>({1, 2, 3, 4})),
                    std::make_tuple(std::vector<int>({-1, 5, 3, 4, 0}), std::vector<int>({-1, 0, 3, 4, 5}))));
}  // namespace leetcode_147