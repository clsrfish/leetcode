// Unit tests for LeetCode Solution 82
#include <gtest/gtest.h>
#include <string>
#include <tuple>
#include <vector>

#include "../../src/leetcode/82.cpp"
#include "../utils/list_util.hpp"
namespace {
class LeetCode82 : public testing::TestWithParam<
                       std::tuple<std::vector<int>, std::vector<int>>> {
protected:
  leetcode_82::Solution solution;
  LeetCode82() {}
  ~LeetCode82() override {}
  void SetUp() override {
    std::vector<int> nums;
    std::tie(nums, expected) = GetParam();
    head = createList(nums);
  }
  void TearDown() override {

  }
  ListNode *head;
  std::vector<int> expected;
};

// test_suite_name, test_name
TEST_P(LeetCode82, Test) {
  auto actual = solution.deleteDuplicates(head);
  ASSERT_EQ(expected, listToVector(actual));
  freeListNodes(actual);
}

// prefix, test_suite_name
INSTANTIATE_TEST_SUITE_P(
    P, LeetCode82,
    testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 3, 4, 4, 5},
                                    std::vector<int>{1, 2, 5}),
                    std::make_tuple(std::vector<int>{1, 1, 1, 2, 3},
                                    std::vector<int>{2, 3})));
} // namespace